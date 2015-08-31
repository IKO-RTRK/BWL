int ourRandom(void){
  unsigned int m = 1024;
  unsigned int a = 1101;
  unsigned int c = 1023;
  unsigned int z;
  unsigned int result = (a*z + c) % m;

  return result;
}
