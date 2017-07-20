#ifndef _INC_CFG_OP_H
#define _INC_CFG_OP_H

#ifdef _cplusplus
extern "c"{
#endif

int GetCfgItem(char* pfilename/*in*/,char* pkey/*in*/,char* pvalue/*in out*/,int *pvaluelen/*out*/);

int WriteCfgItem(char* pfilename/*in*/,char* pItemname/*in*/,char* pitemvalue/*in*/,int itemvaluelen/*in*/);






#ifdef _cplusplus
}
#endif

#endif
