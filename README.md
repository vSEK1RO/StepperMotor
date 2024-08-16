<h1 align="center"> StepperMotor </h1>

<img src="https://i.imgur.com/G55AsJR.png"></img>

#### Поддерживается для Arduino Mega 2560 / Supported for Arduino Mega 2560

>Данный проект представляет собой прошивку для 12-фазного __шагового__ электродвигателя с возможностью смены режимов работы.

>This project is a firmware for a 12-phase __stepper__ electric motor with the ability to change operating modes.

### Видео-демострация работы двигателя доступна здесь / Video demonstration:

https://user-images.githubusercontent.com/114253920/219883985-04ecfcb7-5d5b-41b1-b43f-c0dca7d3a889.mp4

<h1 align="center"> Инструкция по сборке / Assembly instructions </h1>

### Для сборки модели шагового двигателя необходимо было изготовить:

- статор, состоящий из 4 электромагнитов, закрепленных на
алюминиевой рамке.
- ротор, состоящий из 6 постоянных магнитов, расположенных по
сторонам правильного шестиугольника.
- контроллер шагового двигателя на базе микроконтроллера arduino, а
также драйвера шагового двигателя L298N (*)

(*) Драйвер L298N - полный H-мост, те электронная схема, которая дает
возможность приложить напряжение к нагрузке в разных направлениях.
Используется для многофункционального управления двигателями постоянного
тока, имеет возможность изменять скорость и направление вращения моторов. Для
управления используются командные входы, представляющие собой штыревые
контакты.

### To assemble a stepper motor model, it was necessary to make:

- a stator consisting of 4 electromagnets fixed on
aluminum frame.
- a rotor consisting of 6 permanent magnets arranged along
sides of a regular hexagon.
- stepper motor controller based on arduino microcontroller, and
also stepper motor driver L298N (*)

(*) The L298N driver is a full H-bridge, those electronic circuitry that gives
the ability to apply voltage to the load in different directions.
Used for multifunctional DC motor control
current, has the ability to change the speed and direction of rotation of the motors. For
control, command inputs are used, which are pin
contacts.

<img src="https://i.imgur.com/yjuqhhx.jpg" height="500vh"></img>

<h1 align="center"> Фото материалы / Photo materials </h1>

<h2 align="center"> Готовая модель / Finished model </h2>

<img src="https://i.imgur.com/oSCZ4uL.jpg" height="500vh"></img>

<h2 align="center"> Корпус / Frame </h2>

<img src="https://i.imgur.com/fuuxSnN.jpg" height="500vh"></img>

<h2 align="center"> Электромагнит / Electromagnet </h2>

<img src="https://i.imgur.com/y6qFl9Q.jpg" height="500vh"></img>

<h2 align="center"> Ротор / Rotor </h2>

<img src="https://i.imgur.com/biA783y.jpg" height="500vh"></img>
