hour, minute=map(int,input().split())
time=int(input())

hour+=time//60
minute+=time%60

if minute>=60:
	hour+=1
	minute-=60

if hour>=24:x
	hour-=24

print(hour, minute)

#if minute+time<60:
#	print(hour, minute+time) 
#elif minute+time>=60:
#	if hour+((minute+time)//60)>=24:
#		print(hour+(minute+time)//60)-24, (minute+time-60)%60
#	elif hour+((minute+time)//60)<24:
#		print(hour+(minute+time)//60), (minute+time-60)%60
