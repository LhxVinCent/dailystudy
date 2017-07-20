#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LineMaxLen 2048
#define KeyMaxLen 64
int GetCfgItem(char* pfilename/*in*/,char* pkey/*in*/,char* pvalue/*in out*/,int *pvaluelen/*out*/)
{
 int rv=0;
FILE *fp=NULL;
char linebuf[LineMaxLen];
char* pBegin=NULL;
char* pEND=NULL;
char* pTmp=NULL;
if(pfilename==NULL || pkey==NULL || pvalue==NULL || pvaluelen==NULL)
 {
   rv=-1;
   goto END;
 }	 

fp=fopen(pfilename,"r");

if(fp==NULL)
{
  rv=-2;
  goto END;
}

while(!feof(fp))
{
   memset(linebuf,0,LineMaxLen);
   pTmp=fgets(linebuf,LineMaxLen,fp);
   if(pTmp==NULL)
   {
	   break;
   }
   pTmp=strchr(linebuf,'=');
   if(pTmp==NULL)
   {
     continue;
   }
   pTmp=strstr(linebuf,pkey);
   if(pTmp==NULL)
   {
     continue;
   }
   pTmp=strchr(linebuf,'=');
   if(pTmp==NULL)
   {
       continue;
   }
   pTmp=pTmp+1;

   while(1)
   {
     if(*pTmp==' ')
	 {
        pTmp++;
	 }
	 else{

       pBegin=pTmp;
       if(*pBegin=='\n')	   
	   {
           goto END;
	   }
	   break;
	 }
   }


   while(1)
   {
      if(*pTmp==' ' || *pTmp=='\n')
	  {
          break;
	  }
	  else {
       pTmp++;
	  }
   }

   pEND=pTmp;
   *pvaluelen=pEND-pBegin;
   memcpy(pvalue,pBegin,pEND-pBegin);
   break;


}

END:
   if(fp!=NULL)
   {
     fclose(fp);
   }
return rv;
}
int WriteCfgItem(char* pfilename/*in*/,char* pItemname/*in*/,char* pItemvalue/*in*/,int itemvaluelen/*in*/)
{

     
    int rv=0;
    FILE *fp=NULL;
	int length=0;
	int itag=0;
    char linebuf[LineMaxLen];	
	char *pTmp=NULL,*pBegin=NULL,*pEnd=NULL;
	char filebuf[1024*8]={0};
	if(pfilename==NULL || pItemname==NULL || pitemvalue==NULL)
	{
       rv=-1;
	   goto END;
	}
	fp=fopen(pfilename,"r+");
       
	if(fp==NULL)
	{
       rv=-2;
	}

	if(fp==NULL)
	{

       fp=fopen(pfilename,"wt");

	   if(fp==NULL)
	   {
         rv=-3;
		 goto END;
	   }
	}
	

	fseek(fp,0L,SEEK_END);
    length=ftell(fp);
	fseek(fp,0L,SEEK_SET);

    if(length>1024*8)
	{
      rv=-3;
	  goto END;
	}

	while(!feof(fp))
	{
        
     memset(linebuf,0,sizeof(linebuf));

	 pTmp=fgets(linebuf,LineMaxLen,fp);

	 if(pTmp==NULL)
	 {
        break;
	 }

    pTmp=strstr(linebuf,pItemname);
	 if(pTmp==NULL)
	 {
	  strcat(filebuf,linebuf);
       continue; 
	 }
     else{

     sprintf(linebuf,"%s = %s\n",pItemname,pItemvalue);
	 strcat(filebuf,linebuf);
	 itag=1;
	 }
	}
 if(itag==0)
 {
     fprintf(fp,"%s = %s\n",pItemname,pItemvalue);
 }else{

	 if(fp!=NULL)
	 {
       fclose(fp);
	   fp=NULL;
	 }
	 fp=fopen(pfilename,"w+t");
	 
	 if(fp==NULL)
	 {
        rv=-4;
		goto END;
	 }

     fputs(filebuf,fp);

 }

END:
	if(fp!=NULL)
	{
       fclose(fp);
	}

return rv;
}





