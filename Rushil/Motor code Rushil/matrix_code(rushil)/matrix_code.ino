/*code for matrix
 * matrix : A[y][x]
 matrix corresponds only to the second quadrant so far
 */
 struct node
 {
  bool dirr;bool dirl;
  int r;
  int l;
 }
node a[512][512];
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<512;i++)
  {
    for(int j=0;j<512;j++)
    {
      if(i==j)
      {
        dirr = 1; dirl = 0;
        r = map(i,0,512,255,0);
        l = 0;
      }
      if(i<j)
      {
        dirr = 1; dirl = 1;
       r = map(i,0,512,255,0);
       l = map(j,0,512,0,255);
      }
      if(i>j)
      {
        dirr = 1; dirl = 0;
        r = map(j,0,512,255,0);
        l = map(i,0,512,255,0);
      }
    }
  }

}
//make a function to retrieve values and for analogWrite

void loop() {
  // put your main code here, to run repeatedly:

}
