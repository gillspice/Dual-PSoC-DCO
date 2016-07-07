
//`#start header` -- edit after this line, do not edit this line
// ========================================
//
// Copyright YOUR COMPANY, THE YEAR
// All Rights Reserved
// UNPUBLISHED, LICENSED SOFTWARE.
//
// CONFIDENTIAL AND PROPRIETARY INFORMATION
// WHICH IS THE PROPERTY OF your company.
//
// ========================================
`include "cypress.v"
//`#end` -- edit above this line, do not edit this line
// Generated on 07/01/2016 at 08:41
// Component: UpDownCounter
module UpDownCounter (
	output  div_out,
	input   Clock,
	input   Count_Up,
	input   Reset
);

//`#start body` -- edit after this line, do not edit this line

//        Your code goes here
  reg [3:0] count;
   
  always @(posedge Clock)
  begin
    if (Reset)
      count <= 0;
    else if (Count_Up)
      count <= count + 1;
    else
      count <= count - 1;
  end
  assign div_out = count[3];
//`#end` -- edit above this line, do not edit this line
endmodule
//`#start footer` -- edit after this line, do not edit this line
//`#end` -- edit above this line, do not edit this line
