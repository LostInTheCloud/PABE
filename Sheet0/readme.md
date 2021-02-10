# PABE Sheet 0

## Task 2

```asm
xor eax, eax        ;eax=0
xor ebx, ebx        ;ebx=0
xor ecx, ecx        ;ecx=0
mov ecx, 1          ;ecx=1      
mov eax, 1337       ;eax=leet
mov ebx, 42         ;ebx=42
add eax, ebx        ;eax=1379
shl ecx, 2          ;ecx=4
add eax, ecx        ;eax=1383
push eax            ;|1383|
push ebx            ;|1383|42|
pop ecx             ;ecx=42
pop edx             ;edx=1383
lea eax, [ecx+eax]  ;eax=1425
lea ebx, [edx+ebx]  ;ebx=1425
```

-> EAX = `1425`  
-> EBX = `1425`  
-> ECX = `1383`  
-> EDX = `1383`

## Task 5

```
lenni@PC ~ (master)> nc pabe.seclab-bonn.de 11338
Please enter a name (max. 8 chars): lenni

Welcome lenni!
You have 8 jetons. Round 1 is about to start.
1 - bet
2 - options
3 - quit
2
Welcome to the options menu. What would you like to do?
1 - rules
2 - set name
3 - ask for credit
2
Please enter a name (max. 8 chars): aaaaaaaaaaaaaaaaaaaaaaaa

Welcome aaaaaaaaaaaaaaaaaaaaaaaa!
You have 8 jetons. Round 1 is about to start.
1 - bet
2 - options
3 - quit
1
Faites vos jeux!
On what do you want to bet? [0-36, red|black, even|odd]
97
How much would you like to bet? [1-8]
8
Rien ne va plus!

...| 21 | 13 | 9 |...
          O

...| 31 | 5 | 9 |...
          O

...| 13 | 34 | 27 |...
          O

...| 34 | 27 | 97 |...
          O

...| 27 | 97 | 16 |...
          O


... its a 97 (red / odd)!
97 97 red 8 odd
You won 288 Jetons!

You have 296 jetons. Round 2 is about to start.
1 - bet
2 - options
3 - quit
1
Faites vos jeux!
On what do you want to bet? [0-36, red|black, even|odd]
97
How much would you like to bet? [1-296]
296
Rien ne va plus!

...| 2 | 23 | 15 |...
          O

...| 4 | 5 | 31 |...
          O

...| 0 | 13 | 4 |...
          O

...| 13 | 4 | 97 |...
          O

...| 4 | 97 | 10 |...
          O


... its a 97 (red / odd)!
97 97 red 296 odd
You won 10656 Jetons!

You won!
FLAG{327a6c4304ad5938eaf0efb6cc3e53dc}⏎
lenni@PC ~ (master)>
```