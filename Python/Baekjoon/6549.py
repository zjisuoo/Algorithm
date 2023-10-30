import math
import sys

input = lambda: sys.stdin.readline().rstrip()
MAX = 1000000000

def make_seg(idx, s, e) :
	if s == e :
		seg[idx] = histograms[s]
		return seg[idx]

	mid = (s+e)//2
	l = make_seg(idx*2, s, mid)
	r = make_seg(idx*2+1, mid+1, e)
	seg[idx] = min(l, r)
	return seg[idx]

def f(frm, to) :
	if frm == to :
		return histograms[frm]

	mid = (frm+to) // 2
	l = f(frm, mid)
	r = f(mid+1, to)

	max_val = max(l, r)

	h = min(histograms[mid], histograms[mid+1])
	w = 2
	s = w * h
	i, j = mid, mid+1
	while frm < i or j < to :
		if j == to or frm < i and histograms[i-1] >= histograms[j+1] :
			i -= 1
			w += 1
			h = min(h, histograms[i])
			s = max(s, w*h)
		else :
			j += 1
			w += 1
			h = min(h, histograms[j])
			s = max(s, w*h)

	max_val = max(max_val, s)

	return max_val

while True :
	inp = list(map(int, input().split()))
	N = inp[0]
	if N == 0 :
		break
	histograms = inp[1:]

	B = math.ceil(math.log2(N)) + 1
	node_n = 1 << B
	seg = [0] * node_n
	make_seg(1, 0, len(histograms)-1)

	print(f(0, len(histograms)-1))