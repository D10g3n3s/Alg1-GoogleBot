#ifndef SITE_H
    #define SITE_H

    #include "boolean.h"
    #include "utils.h"
    
    #define ERROR 1337;

    typedef struct _site SITE;
    typedef struct _words WORDS;

    SITE* createSite(char *string);
    bool deleteSite(SITE *site);
    void printSite(SITE *site);
    int siteGetCode(SITE *site);
    char* siteGetName(SITE *site);
    int siteGetRevelance(SITE *site);
    char* siteGetLink(SITE *site);
    char** siteGetKeyWords(SITE *site);
    int siteGetAmountKeyWords(SITE *site);
    bool siteSetRelevance(SITE *site, int relevance);
    bool siteSetKeyWord(SITE *site, char *string);

#endif