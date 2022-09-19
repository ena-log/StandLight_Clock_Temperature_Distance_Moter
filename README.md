# StandLight
라즈베리파이를 이용한 탁상용 스탠드 개발 코드

# Software Diagram
UML CLASS DIAGRAM
![image](https://user-images.githubusercontent.com/103064030/190898827-361473bc-b57b-45b4-a3f1-813122d5b3c1.png)

# Function
<ol>
  <li><strong> Button </strong></li>
  <ul>
    <li>버튼1 : LED 밝기 조절 </li>
    <li>버튼2 : POWER ON/OFF </li>
      LCD BACK LIGHT ON/OFF
    <li>버튼3 : MOTOR(FAN) ON/OFF </li>
      PWM 으로 DC MOTOR 제어
    <li>버튼4 : CLOCK ON/COUNTER START/COUNTER STOP</li>
      Counter은 counter up 기능을 의미함
  </ul>
  <p>
  <li><strong>LED Display</strong></li>
  <ul>
    <li>밝기 조절 (단계 : 0,1,2,3,4,5)</li>
  </ul>
  <p>
  <li><strong> LCD Display </strong></li>
  <ul>
    <li>LCD 0 0 : LED 모드 상태 표시 (light off, light 1, light 2, light 3, light 4,light 5)</li>
    <li>LCD 0 9 : 온도 (C)</li>
    <li>LCD 1 0 : CLOCK ON/COUNTER START/COUNTER STOP (hh:mm:ss)</li> 
    <li>LCD 1 9 : 습도 (%)</li>
  </ul>
  <p>
  <li><strong>온습도 센서</strong></li>
  <ul>
    <li>온도, 습도 측정</li>
    <li>온도가 높으면 warning message LCD 출력 + LCD LIGHT OFF MODE</li>
    <li>온도가 높으면 MOTOR(FAN) 동작</li>
  </ul>
  <p>
  <li><strong>초음파 센서</strong></li>
  <ul>
    <li>거리 측정</li>
    <li>사용자 부재시 LIGHT OFF, 사용자 접근시LIGHT ON</li>
  </ul>
  <p>
</ol>

# HW
![StandLight_HW_Result](https://user-images.githubusercontent.com/103064030/190936338-c968fd54-a5c0-4506-8dda-f31644cf814e.PNG)
![StandLight_Motor(PWM)_Data](https://user-images.githubusercontent.com/103064030/190936343-8902968d-c522-4f74-80fb-808203ebcbd9.PNG)

