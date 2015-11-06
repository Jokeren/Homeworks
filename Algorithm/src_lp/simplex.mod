var x1;
var x2;
minimize obj: 1 * x1 + 2 * x2;
s.t. c1: -1 * x1 - 1 * x2 <= -2;
s.t. c2: 1 * x1 + 1 * x2 <= 1;
s.t. c3: x1 >= 0;
s.t. c4: x2 >= 0;
solve;
display x1, x2;
end;
