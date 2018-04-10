var grid; //varijabla canvas,tj. platno,tj. dio na kojem cemo stvoriti nas maze
var ctx;	//varijabla ctx = kontekst , dopusta da crtamo u canvas
var output;


var WIDTH=1200;
var HEIGHT=800;

var dragok=false;

boundX=0;
boundY=0;

tileW=20;
tileH=20;

tileRowCount=25;
tileColumnCount=25;

var tiles=[];

for(c=0;c<tileColumnCount;c++)
{
	tiles[c]=[];
	for(r=0;r<tileRowCount;r++)
	{
		tiles[c][r]={x: c*(tileW+3),y: r*(tileH+3), state: 'e'};
	}
}

tiles[0][0].state='s';
tiles[tileColumnCount-1][tileRowCount-1].state='f';

function rect(x,y,w,h,state)
{
	if (state=='s') { ctx.fillStyle='#00FF00'; }
	else if (state=='f') { ctx.fillStyle='#FF0000'; }
	else if (state=='e') { ctx.fillStyle='#AAAAAA'; }
	else if (state=='w') { ctx.fillStyle='#0000FF'; }
	//else if (state=='x') { ctx.fillStyle='#000000'; }
	else { ctx.fillStyle='#FFFF00'; }
	
	ctx.beginPath();
	ctx.rect(x,y,w,h);
	ctx.closePath();
	ctx.fill();
}

function clear()
{
	ctx.clearRect(0,0,WIDTH,HEIGHT);

}

function draw()
{
	clear();
	for(c=0;c<tileColumnCount;c++)
	{
		for(r=0;r<tileRowCount;r++)
		{
			rect(tiles[c][r].x,tiles[c][r].y,tileW,tileH,tiles[c][r].state);
		}
	}
}

function txt()
{
	for(c=0;c<tileColumnCount;c++)
	{
		for(r=0;r<tileRowCount;r++)
		{
			if(tiles[c][r].state == 's')
				document.write("4 ");
			if(tiles[c][r].state == 'f')
				document.write("8 ");
			if(tiles[c][r].state == 'w')
				document.write("5 ");
			if(tiles[c][r].state == 'e')
				document.write("1 ");
		}
		document.write('<br />');
	}
}


function reset()
{
	for(c=0;c<tileColumnCount;c++)
	{
		tiles[c]=[];
		for(r=0;r<tileRowCount;r++)
		{
			tiles[c][r]={x: c*(tileW+3),y: r*(tileH+3), state: 'e'};
		}
	}

	tiles[0][0].state='s';
	tiles[tileColumnCount-1][tileRowCount-1].state='f';
	
	output.innerHTML='';
}


function init()
{
	grid = document.getElementById("myCanvas");
	ctx=grid.getContext("2d");
	output=document.getElementById("outcome");
	return setInterval(draw,10);
}

function myMove(e)
{
	x=e.pageX-grid.offsetLeft;
	y=e.pageY-grid.offsetTop;
	
	for(c=0;c<tileColumnCount;c++)
	{
		for(r=0;r<tileRowCount;r++)
		{
			if(c*(tileW+3)<x && x<c*(tileW+3)+tileW && r*(tileH+3)<y && y<r*(tileH+3)+tileH)
			{
				if(tiles[c][r].state=='e' && (c!=boundX || r!=boundY)) 
				{ 
					tiles[c][r].state='w'; 
					boundX=c;
					boundY=r;
				}
				else if(tiles[c][r].state=='w' && (c!=boundX || r!=boundY)) 
				{ 
					tiles[c][r].state='e'; 
					boundX=c;
					boundY=r;
				}
			}
		}
	}
}

function myDown(e)
{
	grid.onmousemove=myMove;
	
	x=e.pageX-grid.offsetLeft;
	y=e.pageY-grid.offsetTop;
	
	for(c=0;c<tileColumnCount;c++)
	{
		for(r=0;r<tileRowCount;r++)
		{
			if(c*(tileW+3)<x && x<c*(tileW+3)+tileW && r*(tileH+3)<y && y<r*(tileH+3)+tileH)
			{
				if(tiles[c][r].state=='e') 
				{ 
					tiles[c][r].state='w'; 
					boundX=c;
					boundY=r;
				}
				else if(tiles[c][r].state=='w') 
				{ 
					tiles[c][r].state='e'; 
					boundX=c;
					boundY=r;
				}
			}
		}
	}
}

function myUp()
{
	grid.onmousemove=null;
}

init();
grid.onmousedown=myDown;
grid.onmouseup=myUp;
