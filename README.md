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
</p>
電路圖如下：
![image](https://github.com/8-kami/ARDUINO_109-1/blob/master/USER_SCOPED_TEMP_DATA_orca-image--1870013025.jpeg)

__2020.9.1__ </p>
__四顆LED同時亮滅__ </p>
電路圖如下：
![image](https://github.com/8-kami/ARDUINO_109-1/blob/master/20200908.jpg)

__2020.9.8__ </p>
