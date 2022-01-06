
//  XMAS4

uint16_t pmap[8]={1,5,6,7,8,9,10,11};

uint16_t pats[8]={0xff, 0x52, 0x25, 0xee, 0x44, 0x77, 0x55, 0x00};
uint16_t pats2[10]={0x0, 0x1, 0x2, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0xff};
uint16_t pats3[8]={0xe0, 0x70, 0x38, 0x1c, 0x0e, 0x07, 0x03, 0x01};
uint16_t pats4[]={0x18, 0x3c, 0x7e, 0xff, 0x7e, 0x3c, 0x18, 0xff};
long randomNumber;
uint16_t shift, temp;
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i<10; i++) {
pinMode(i+1, OUTPUT);
  }
  // seed the random number generator
randomSeed(analogRead(0));
}
//===============================================================
// the vec parm 8 bits, lsb turns on ch 1, msb ch 8
void update(uint16_t vec)
{
  uint16_t k, v;
  v=vec;
  for (int i = 0; i<8; i++){
  k = v & 0x1;
  v = v>>1;
  digitalWrite(i+1,k);
  }
};
// output a pattern vector
void patout(uint16_t p[], uint16_t cnt, uint16_t dly, uint16_t reps){
  for (int l=0; l<reps; l++){
  for (int i=0; i<cnt; i++)
  { update(p[i]);
  delay(dly);
  }
  }
  }
void flash(uint16_t num){
  for (int k=0; k<num; k++){
    update(0xff);
    delay (100);
    update (0x00);
    delay (50);
  }
}
//======================================================================================================
void loop() {
  // put your main code here, to run repeatedly:
 
//=========================================================================================
flash(1);
patout (pats, sizeof(pats), 80,20);
patout(pats3,sizeof(pats3),100,30);
patout(pats3,8,50,20);
flash(1);
patout(pats2,sizeof(pats2),100,20);
patout(pats4,sizeof(pats4), 100, 30);
b:; // test code
//goto a1;
// do random delay amounts
for (int j=0; j<10; j++){
randomNumber = random(40, 90);
for (int i = 1; i<9 ; i++) {
  update(pats2[i]);
  delay(randomNumber);
}
}
a1:;
// feed random number to update
for (int i=0; i<70; i++){
  temp = random(0, 1067) & 0xff;
  update (temp);
  delay (40);
}

a: ;
flash(10);
patout(pats4,sizeof(pats4), 100, 30);
patout(pats3,8,40,30);
patout(pats3,sizeof(pats3),40,20);
patout(pats2,sizeof(pats2),40,20);
patout(pats, sizeof(pats),100,15);
flash(10);
// seq blink

for (int j=0; j<10; j++){
{shift = 0x03;
for (int m=0; m<7; m++) {
  update(shift);
  temp=shift<<1;
  shift=temp;
  delay(80);
} 
}
// feed random number to update
for (int i=0; i<50; i++){
  temp = random(0, 512) & 0xff;
  update (temp);
  delay (40);
}
// seq blink
flash(2);
for (int j=0; j<10; j++){
shift = 0xc0;
for (int m=0; m<8; m++) {
  update(shift);
  temp=shift>>1;
  shift=temp;
  delay(100);
} 
}
}

z: flash (8);
}
