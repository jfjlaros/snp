#include <stdio.h>  // printf().
#include <string.h> // strcmp(), strcpy().
#include <expat.h>  // XML functions (use -lexpat when compiling), provided
                    // by libexpat1-dev.

#define BUFFSIZE 8192

char Buff[BUFFSIZE],
     Allele[4],     // Buffer for the last alleles.
     rsId[10],      // Buffer for the last rs id.
     popId[10];     // Buffer for the last population id.

int count,    // Counter for the number of alleles.
    skip = 0;

float minFreq,             // The minimum frequency of an allele.
      FreqThreshold = 0.0; // The threshold of the minimum frequency.

static void XMLCALL start(void *data, const char *el, const char **attr) {
  float temp;

  if (!strcmp(el, "SnpInfo"))
    strcpy(rsId, attr[1]);
  if (!strcmp(el, "ByPop")) {
    strcpy(popId, attr[1]);
    count = 0;
    minFreq = 1.0;
  }//if
  if (!strcmp(el, "AlleleFreq")) {
    if ((attr[1][0] == '-') || (attr[1][1] != '\0'))
      skip = 1;
    if ((attr[1][0] != '(') && (attr[1][0] != 'N') && !skip) {
      Allele[count] = attr[1][0];
      temp = atof(attr[3]);
      if (temp < minFreq)
        minFreq = temp;
      count++;
    }//if
  }//if
}//start

static void XMLCALL end(void *data, const char *el) {
  int i;

  if (!strcmp(el, "ByPop")) {
    if ((count > 2) && (minFreq >= FreqThreshold) && !skip) {
      printf("rsId: %s, popId: %s, minFreq: %f, ", rsId, popId, minFreq);
      for (i = 0; i < count; i++)
        printf("%c ", Allele[i]);
      printf("\n");
    }//if
    skip = 0;
  }//if
}//end

int main(int argc, char *argv[]) {
  XML_Parser p = XML_ParserCreate(NULL);
  int done = 0,
      len;

  if (!p) {
    fprintf(stderr, "Couldn't allocate memory for parser\n");
    exit(-1);
  }//if
  if (argv[1])
    FreqThreshold = atof(argv[1]) / 100;

  XML_SetElementHandler(p, start, end);

  while (!done) {
    len = fread(Buff, 1, BUFFSIZE, stdin);
    if (ferror(stdin)) {
      fprintf(stderr, "Read error\n");
      return -1;
    }//if
    done = feof(stdin);
    if (XML_Parse(p, Buff, len, done) == XML_STATUS_ERROR) {
      fprintf(stderr, "Parse error at line %d:\n%s\n",
              (int)XML_GetCurrentLineNumber(p),
              XML_ErrorString(XML_GetErrorCode(p)));
      return -1;
    }//if
  }//while

  return 0;
}//main
