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

<h5> __增至八顆LED__ </h5></p>
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
Step1.○○○○○○○○ </p>
Step2.●○○○○○○○ </p>
Step3.○●○○○○○○ </p>
Step4.○○●○○○○○ </p>
Step5.○○○●○○○○ </p>
Step6.○○○○●○○○ </p>
Step7. ○○○○○●○○ </p>
Step8. ○○○○○○●○ </p>
Step9. ○○○○○○○● </p>
↑BACK TO Step1. </p>
