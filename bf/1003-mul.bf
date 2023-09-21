,> input number at cell #0
+++ +++
[<---- ---- > -]#subtracts 8 6 times = 48

,> input number at cell #1
+++ +++
[<---- ---- > -]#subtracts 8 6 times = 48

#DOING THE MULTIPLICATION
<<
[
 > go to cell #1
 [
   ->+>+<< move data to cell #2 #3
 ]
 >> go to cell #3
 [
  -<<+>> move data to cell #1
 ]
 <<< go to cell #0
 - decrement cell #0
]

>> MOVE TO CELL 2 CONTAINING THE OUTPUT
#PRINTING

[                        While X is not null
  >>>>++++++++++<<<<     (10)
  [->+>>+>-[<-]<[<<[->>  Divide X by 10
  >+<<<]>>>>+<<-<]<<]    ** part 2 **
  ++++++++[->++++++<]>   add 48 to remainder
  [-<+>]                 Move remainder at X location
  >>>>[-<<<<+>>>>]       Put quotient at new X location
  <[-]<<<                Reset cells
]                        Loop


<[.<]                    Print backwards


[-]
+++++ +++++.
