fibonacci(n)
if (n<0) then
stop;
if (n=<1) then
return n;
f1 = 0;
f2 = 1;
for(i=2 ; i=<n ; i=i+1) do {
	fn=f1+f2;
	f1=f2;
	f2=fn;
}
return fn;
end