#include"InputPly.h"
#include"Vertex.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<timer.h>
using namespace std;

 int cntvrow,cntfrow;
//extern float **vertex;
 unsigned int **faces;
float **vn;
float **nrml;
Vertex *vertex;


void readPly(char* path)
{
    int i=0,j=1;
	int cntflag=0;
	char buffer[500];
    char s1[20],s2[20];    //for reading extra strings
    int cntvcol=0;           //count number of columns of verticies
    int cntfcol=0;           //count number of columns of faces

	char* ifvalid = strstr(path,".ply");
	if(ifvalid!=NULL)
	{
		FILE* file=fopen(path,"r");
		while(!strstr(buffer,"end_header"))                  //Reading number of vertices and faces
		{
		  if(fgets(buffer,500,file))
		    {

			   if(strstr(buffer,"element vertex"))
			     {
			        cntflag=1;
			        sscanf(buffer,"%s %s %d",s1,s2,&cntvrow);
			     }

			   if(strstr(buffer,"element face"))
			     {
                    cntflag=2;
                    sscanf(buffer,"%s %s %d",s1,s2,&cntfrow);
			     }
               if(cntflag==1)
			     cntvcol++;
		    }
		}
    cntvcol=cntvcol-1;
    //Initialing Vertex array
     vertex= new Vertex[(cntvrow)];
    // for (int x = 0;x < (cntvrow);x++)
      //  vertex[x] =new float[cntvcol];

    //Reading Vertex Values
     while(i!=cntvrow)
     {
  //     for (int p=0;p<cntfcol;p++)
        {
          fscanf(file,"%f %f %f",&vertex[i].x,&vertex[i].y,&vertex[i].z);
         }
        i++;
     }
    //Getting number of columns of face
     fscanf(file,"%d",&cntfcol);
     cntfcol=cntfcol+1;
     //Initialing Faces array
     faces= new unsigned int*[(cntfrow)];
     for (int x = 0;x < (cntfrow);x++)
        faces[x] =new unsigned int[cntfcol];

     faces[0][0]=cntfcol-1;
     for (int p=1;p<cntfcol;p++)
       fscanf(file,"%d",&faces[0][p]);

    //Reading Faces Values
     while(j!=cntfrow)
     {
        for (int p=0;p<cntfcol;p++)
          fscanf(file,"%d",&faces[j][p]);
        j++;
     }
   //  for(int i=0;i<cntfrow-1;i++)
//     getNormal(i);


	}
    else
    {
      std::cout<<"Enter a .ply file";
      exit(0);
    }
 i=0;
//printf("hello");
     while(i!=cntvrow)
     {
       // for (int p=0;p<cntfcol;p++)
        {
         printf("%f %f %f",vertex[i].x,vertex[i].y,vertex[i].z);
           printf("\n");
         }
        i++;
     }
}
