clc
clear all;
syms x1;
syms x2;
syms x3;
syms v1;
syms v2;
syms v3;
Fx=[x1^3-2*x2-2; x1^3-5*x3^2+7; x2*x3^2-1];
Jacobi=[diff(Fx(1),x1) diff(Fx(1),x2) diff(Fx(1),x3); diff(Fx(2),x1) diff(Fx(2),x2) diff(Fx(2),x3);  diff(Fx(3),x1) diff(Fx(3),x2) diff(Fx(3),x3)];
flag=true;
i=0;
x1=1; x2=1; x3=1; 
while flag==true
    gh=subs(Jacobi);
    func=subs(Fx);
    gh=inv(gh);
    v0=gh*func;
    i=i+1;
    x11=x1-v0(1);
    x21=x2-v0(2);
    x31=x3-v0(3);
   if (x11-x1)<0.0001 && (x21-x2)<0.0001 && (x31-x3)<0.0001
        flag=false;
        break;
   end
   x1=x11;
   x2=x21;
   x3=x31; 
end
disp('It took i iterations')
i
disp('The solution is')
x1
x2
x3