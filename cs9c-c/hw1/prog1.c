#include <stdio.h>

int isVowel (char input, int index, int qIndex);

int main ()
{
   char walker;
   // char buffer[256];
   char consonantBuffer[256];
   // char isBeginVowel = 0;
   int index;
   int qIndex;
   int i;
   char first;
   int consBufIndex;
 
  while(1){

    // Process first character
    index = 0;
    qIndex = -1;
    consBufIndex = 0;   
    first = getchar();
    if(first == '\n') {
      break;
    }
    if(first == 'q') {
      qIndex = index;
    }

    if (isVowel(first, index, qIndex)) {
      putchar(first);
      while((walker = getchar()) != '\n') {
        putchar(walker);
      }
      putchar('y');
      putchar('a');
      putchar('y');
    } else {
      // Put first charcter to consonant buffer
      consonantBuffer[consBufIndex] = first;
      consBufIndex++;
      index++;

      walker = getchar();
      while (walker != '\n' && !isVowel(walker, index, qIndex)) {
        if (walker == 'q') {
          qIndex = index;
        }
        consonantBuffer[consBufIndex] = walker;
        consBufIndex++;
        index++;
        walker = getchar();
      }

      while (walker != '\n') {
        putchar(walker);
        walker = getchar();
      }
      for(i = 0; i < consBufIndex; i ++){
        putchar(consonantBuffer[i]);
      }
      putchar('a');
      putchar('y');
    }
    putchar('\n');
  }
  return(0);
}

int isVowel (char input, int index, int qIndex){
  int case_y = index != 0 && input == 'y';
  int case_qu = qIndex != -1 && qIndex == index -1;
  return input == 'a' ||
         input == 'e' ||
         input == 'i' ||
         input == 'o' ||
        (input == 'u' && !case_qu) ||
         case_y;
}