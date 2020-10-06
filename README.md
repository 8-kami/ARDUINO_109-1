# ARDUINO_109-1 
ARDUINOmemo </p>
<h3> 學習ARDUINO 的過程 </h3>

*初始設定，只執行一次* </p>
void setup() 

*主程式，會重複執行* </p>
void loop() 

*腳位模式* </p>
pinMode(3, OUTPUT)      //INPUT初始值=1, OUTPUT初始值=0

*寫入電位* </p>
digitalWrite(3, HIGH) 
digitalWrite(3, LOW)

*等待* </p>
delay(500) 

__第一個程式　功能：LED閃爍(亮0.5s 熄0.5s)__ </p>
```c++
void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
      digitalWrite(3, HIGH);
      delay(500);
      digitalWrite(3, LOW);
      delay(500);
      
} 
```

電路圖如下：
![image](https://github.com/8-kami/ARDUINO_109-1/blob/master/USER_SCOPED_TEMP_DATA_orca-image--1870013025.jpeg) </p>

__2020.9.1__ </p>
__第二個程式 功能：四顆LED同時亮滅__ </p>
```c++
int i;
void setup() {
for(i=2; i<6; i++)
  pinMode(i, OUTPUT);
}

void loop() {
  for(i=2; i<6; i++)
  digitalWrite(i, HIGH);
  delay(500);
  for(i=2; i<6; i++)
  digitalWrite(i, LOW);
  delay(500);  
}
```

電路圖如下：
![image](https://github.com/8-kami/ARDUINO_109-1/blob/master/20200908.jpg) </p>

__2020.9.8__ </p>
__第三個程式 功能：四顆LED由左至右，逐一亮滅__ </p>
```c++
int i;
int LED = 5;
void setup() {
for(i=2; i<6; i++)
  pinMode(i, OUTPUT);
}
 
void loop() {
  for(i=5; i>1 ;i--)
    digitalWrite(i, HIGH);
  if (LED>=2)
    digitalWrite(LED, LOW);
  else
    LED=6;
  LED--;
  delay(500);  
}
```
Step1.○○○○ [初始]</p>
Step2.●○○○ </p>
Step3.○●○○ </p>
Step4.○○●○ </p>
Step5.○○○● </p>
↑BACK TO Step1. </p>


電路圖如下：
![image](https://github.com/8-kami/ARDUINO_109-1/blob/master/20200915.jpg) </p>
![image](https://github.com/8-kami/ARDUINO_109-1/blob/master/20200915-1.jpg) </p>

__第四個程式 功能：增至八顆LED 由左至右，逐一亮滅__ </p>
```c++
int i;
int LED = 9;
void setup() {
for(i=2; i<10; i++)
  pinMode(i, OUTPUT);
}
 
void loop() {
  for(i=9; i>1 ;i--)
    digitalWrite(i, HIGH);
  if (LED>=2)
    digitalWrite(LED, LOW);
  else
    LED=10;
  LED--;
  delay(500);  
}
```
Step1. ○○○○○○○○ </p>
Step2. ●○○○○○○○ </p>
Step3. ○●○○○○○○ </p>
Step4. ○○●○○○○○ </p>
Step5. ○○○●○○○○ </p>
Step6. ○○○○●○○○ </p>
Step7. ○○○○○●○○ </p>
Step8. ○○○○○○●○ </p>
Step9. ○○○○○○○● </p>
↑BACK TO Step1. </p>


電路圖如下：
![image](https://github.com/8-kami/ARDUINO_109-1/blob/master/20200915-2.jpg) </p>
![image](https://github.com/8-kami/ARDUINO_109-1/blob/master/20200915-3.jpg) </p>

__增至八顆LED 由右至左，逐一亮滅__ </p>
```c++
int i;
int LED = 2;
void setup() {
for(i=2; i<10; i++)
  pinMode(i, OUTPUT);
}
 
void loop() {
  for(i=2; i<10 ;i++)
    digitalWrite(i, HIGH);
  if (LED<=9)
    digitalWrite(LED, LOW);
  else
    LED=1;
  LED++;
  delay(500);  
}
```
Step1. ○○○○○○○○ </p>
Step2. ○○○○○○○● </p>
Step3. ○○○○○○●○ </p>
Step4. ○○○○○●○○ </p>
Step5. ○○○○●○○○ </p>
Step6. ○○○●○○○○ </p>
Step7. ○○●○○○○○ </p>
Step8. ○●○○○○○○ </p>
Step9. ●○○○○○○○ </p>
↑BACK TO Step1. </p>


電路圖如下：
![image](https://github.com/8-kami/ARDUINO_109-1/blob/master/20200915-4.jpg) </p>
![image](https://github.com/8-kami/ARDUINO_109-1/blob/master/20200915-5.jpg) </p>


__第4+1個程式　功能：呼吸燈__ </p>
```c++
int i;
int l=255;
int add=-15;
void setup() {
 pinMode(3, OUTPUT);
}
 
void loop() { 
  analogWrite(3,l);
  l=l+add;
    if(l == 0)
    {
      add=-add;
    }
    if(l == 255)
    {
      add=-add;
    }
  delay(30);
}
```
or
```c++
int i;
int l=255;
int add=-15;
void setup() {
 pinMode(3, OUTPUT);
}
 
void loop() { 
  analogWrite(3,l);
  l=l+add;
    if(l == 0|| l == 255)
    {
      add=-add;
    }
  delay(30);
}
```
*類比輸出寫法* </p>
analogWrite(腳位,值)

//腳位必要有~符號,值(亮)0-255(暗) </p>
//！建議！亮度增加值l整除255 </p>


電路圖如下：
![image](https://github.com/8-kami/ARDUINO_109-1/blob/master/200915-6.jpg) </p>
![image](https://github.com/8-kami/ARDUINO_109-1/blob/master/20200915-7.jpg) </p>

__2020.9.15__ </p>


__第5個程式 按鈕開關(Tack Switch)__ </p>
```c++
void setup() {
  pinMode(2, INPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH); //
}

void loop() {
  if(digitalRead(2)==0)
  {
    digitalWrite(4,LOW);
    }
}
```
電路圖如下：
![image](https://github.com/8-kami/ARDUINO_109-1/blob/master/20200922-1.jpg) </p>
![image](https://github.com/8-kami/ARDUINO_109-1/blob/master/20200922-2.jpg) </p>

__按鈕開關(Tack Switch) 點擊一下亮、再點一次熄燈__ </p>
```c++
int  a= 0;
void setup() {
  
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4,HIGH);
}

void loop() {
  if(digitalRead(3)==LOW){

    while(digitalRead(3)==LOW);
    a=(a+1)%2;
  }  
  switch(a)
  {
    
    case 0:
    {digitalWrite(4,LOW);}
    case 1:
    {digitalWrite(4,HIGH);}
 
    }
}
```
電路圖如下：
![image](https://github.com/8-kami/ARDUINO_109-1/blob/master/20200929_1.jpg) </p>
![image](https://github.com/8-kami/ARDUINO_109-1/blob/master/20200929_2.jpg) </p>

__2020.9.22__ </p>


__第6個程式 按鈕開關(Tack Switch) 功能：以按鈕開關控制LED燈__ </p>
__step1由左往右一一點燃,step2由右往左一一點燃,step3全部熄滅__ </p>
```c++
int a= 0;
int i;
int LED = 12;
int LED2 = 4;
void setup() {
  
  pinMode(3, INPUT);
  for(i=4; i<12; i++)
    pinMode(i, OUTPUT);
    digitalWrite(i,HIGH);
}

void loop() {
  if(digitalRead(3)==LOW){

    while(digitalRead(3)==LOW);
    a=(a+1)%3; //1.2.0

  }  
  switch(a)
  {
    
    case 0:
    {     
     for(i=12; i>3 ;i--)
        digitalWrite(i, HIGH);
     if (LED>=3)
        digitalWrite(LED, LOW);
     else
        LED=13;
     LED--;
     delay(500);
     break;
    }   
    case 1:
    {
     for(i=4; i<12 ;i++)
         digitalWrite(i, HIGH);
     if (LED2<=12)
        digitalWrite(LED2, LOW);
     else
        LED2=3;
      LED2++;
     delay(500);  
     break;      
    }
    case 2:
    {  
     for(i=4;i<12;i++)
     digitalWrite(i, HIGH);
     delay(100);
     break; 
    }
  
  }
    
}
```

電路圖如下：
![image](https://github.com/8-kami/ARDUINO_109-1/blob/master/20200929_3.jpg) </p>

__第7個程式 按鈕控制三個功能：__ </p>

__一：自動切換三色LED燈__ </p>
__二：呼吸燈__ </p>
__三：切換LED六種顏色__ </p>

```c++
int ctrlr,ctrlg,ctrlb;
int rp = 9;
int gp = 10;
int bp = 11;
int l=180;
int add=-10;
int x,y,z=0;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);  
  for(int i=9; i<12; i++)
    pinMode(i, OUTPUT);  
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);  
}

void loop() {
  if(digitalRead(3)==LOW) //切換LED六種顏色
  {
    while(digitalRead(3)==LOW);
    x=(x+1)%6;  //1,2,3,4,5,0
  }
     switch(x)
    {
    case 0:{ctrlr =180;ctrlg =0;ctrlb =0;setColor(ctrlr, ctrlg, ctrlb);break;} 
    case 1:{ctrlg =180;ctrlr =0;ctrlb =0;setColor(ctrlr, ctrlg, ctrlb);break;} 
    case 2:{ctrlb =180;ctrlr =0;ctrlg =0;setColor(ctrlr, ctrlg, ctrlb);break;} 
    case 3:{ctrlr =180;ctrlg =180;ctrlb =0;setColor(ctrlr, ctrlg, ctrlb);break;} 
    case 4:{ctrlr =180;ctrlg =0;ctrlb =180;setColor(ctrlr, ctrlg, ctrlb);break;} 
    case 5:{ctrlr =0;ctrlg =180;ctrlb =180;setColor(ctrlr, ctrlg, ctrlb);break;} 
    }  
    
  if(digitalRead(2)==LOW)  //呼吸燈
  {
    while(digitalRead(2)==LOW);
    y=(y+1)%2;
  }    
  switch(y)
  {
    case 0:
    {
    setColor(l, ctrlg, ctrlb);
    l=l+add;
    if(l == 0 || l == 180)
    {
       add=-add;
    }
    delay(30);
    break;
    }
    case 1:
    {digitalWrite(2, HIGH);delay(100);break;}
  }   
  if(digitalRead(4)==LOW)  //自動切換三色LED燈
  {
    while(digitalRead(4)==LOW);
    z=(z+1)%2;
  } 
    switch(z)
  {
    case 0:
    {
    setColor(80, 0, 0);delay(500);
    setColor(0, 80, 0);delay(500);
    setColor(0, 0, 80);delay(500);break;}
    case 1:
    {digitalWrite(4, HIGH);delay(100);break;}
  }   

}

void setColor(int red, int green, int blue) //副程式
{
  analogWrite(rp, red);
  analogWrite(gp, green);  
  analogWrite(bp, blue);
}
```
