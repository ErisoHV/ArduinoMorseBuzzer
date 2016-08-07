#include "pitches.h"

int NOTE = NOTE_A4;

//The length of a got is one unit
const int DOT = 75;
// A dash is three units
const int DAH = 3*DOT;
// The space between words is seven units
const int SPACE = 7*DOT;

const int A[]{DOT,DAH};          // ._
const int B[]{DAH,DOT,DOT,DOT}; //_...
const int C[]{DAH,DOT,DAH,DOT}; // _._.
const int D[]{DAH,DOT,DOT};     //_..
const int E[]{DOT};             //.
const int F[]{DOT,DOT,DAH,DOT}; //.._.
const int G[]{DAH,DAH,DOT};     //__.
const int H[]{DOT,DOT,DOT,DOT}; //....
const int I[]{DOT,DOT};         //..
const int J[]{DOT,DAH,DAH,DAH };//.___
const int K[]{DAH,DOT,DAH};     //_._
const int L[]{DOT,DAH,DOT,DOT}; //._..
const int M[]{DAH,DAH};         //__
const int N[]{DAH,DOT};         //_.
const int O[]{DAH,DAH,DAH};     //___
const int P[]{DOT,DAH,DAH,DOT}; //.__.
const int Q[]{DAH,DAH,DOT,DAH}; //__._
const int R[]{DOT,DAH,DOT};     //._.
const int S[]{DOT,DOT,DOT};     //...
const int T[]{DAH};             //_
const int U[]{DOT,DOT,DAH};     //.._
const int V[]{DOT,DOT,DOT,DAH}; //..._
const int W[]{DOT,DAH,DAH};     //.__
const int X[]{DAH,DOT,DOT,DAH}; //_.._
const int Y[]{DAH,DOT,DAH,DAH}; //_.__
const int Z[]{DAH,DAH,DOT,DOT}; //__..
const int ZERO[]{DAH,DAH,DAH,DAH,DAH}; //_____
const int ONE[]{DOT,DAH,DAH,DAH,DAH}; //.____
const int TWO[]{DOT,DOT,DAH,DAH,DAH}; //..____
const int THREE[]{DOT,DOT,DOT,DAH,DAH}; //...__
const int FOUR[]{DOT,DOT,DOT,DOT,DAH}; //...._
const int FIVE[]{DOT,DOT,DOT,DOT,DOT}; //.....
const int SIX[]{DAH,DOT,DOT,DOT,DOT}; //_....
const int SEVEN[]{DAH,DAH,DOT,DOT,DOT}; //__...
const int EIGHT[]{DAH,DAH,DAH,DOT,DOT}; //___..
const int NINE[]{DAH,DAH,DAH,DAH,DOT};  //____.


int enableTone(const int* toneArray, int sizeTone){
  int duration = 0;
  for (int i = 0; i < sizeTone; i++) {
    tone(8, NOTE, toneArray[i]);
    // inter-element gap between the dots and dashes within a character : one dot duration or one unit long
    delay(toneArray[i] + DOT); // the space between parts of the same letter is one unit (LETTER TONE + 100)
    duration = duration + toneArray[i]/* + DOT*/; 
    // stop the tone playing:
    noTone(5);
  }
  
  return duration;
}

int toneCharacter(char letter){
  switch(letter){
      case 'A': return enableTone(A, 2); break;
      case 'B': return enableTone(B, 4); break;
      case 'C': return enableTone(C, 4); break;
      case 'D': return enableTone(D, 3); break;
      case 'E': return enableTone(E, 1); break;
      case 'F': return enableTone(F, 4); break;
      case 'G': return enableTone(G, 3); break;
      case 'H': return enableTone(H, 4); break;
      case 'I': return enableTone(I, 2); break;
      case 'J': return enableTone(J, 4); break;
      case 'K': return enableTone(K, 3); break;
      case 'L': return enableTone(L, 4); break;
      case 'M': return enableTone(M, 2); break;
      case 'N': return enableTone(N, 2); break;
      case 'O': return enableTone(O, 3); break;
      case 'P': return enableTone(P, 4); break;
      case 'Q': return enableTone(Q, 4); break;
      case 'R': return enableTone(R, 3); break;
      case 'S': return enableTone(S, 3); break;
      case 'T': return enableTone(T, 1); break;
      case 'U': return enableTone(U, 3); break;
      case 'V': return enableTone(V, 4); break;
      case 'W': return enableTone(W, 3); break;
      case 'X': return enableTone(X, 4); break;
      case 'Y': return enableTone(Y, 4); break;
      case 'Z': return enableTone(Z, 4); break;
      case '0': return enableTone(ZERO, 5); break;
      case '1': return enableTone(ONE, 5); break;
      case '2': return enableTone(TWO, 5); break;
      case '3': return enableTone(THREE, 5); break;
      case '4': return enableTone(FOUR, 5); break;
      case '5': return enableTone(FIVE, 5); break;
      case '6': return enableTone(SIX, 5); break;
      case '7': return enableTone(SEVEN, 5); break;
      case '8': return enableTone(EIGHT, 5); break;
      case '9': return enableTone(NINE, 5); break;
     default: return SPACE; break;
  }
}

void stringToMorse (char* string){
  for (int i=0; i<strlen(string); i++){
          int duration = toneCharacter(toupper(string[i]));
          delay(duration + DAH);  // the space between letters is three units
     
    }
}

void setup() {
  stringToMorse("This is Arduino");
  //- .... .. ... / .. ... / .- .-. -.. ..- .. -. ---
}

void loop() {
  // no need to repeat the melodyDOT
}
