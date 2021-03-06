#include <cstdio>
#include <algorithm>
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;

int  totnum, requirenum, singlelen, totlen, sticklen[64];
bool check(int curlen, int position, int finishnum);
int  cmp(int a, int b) { return a>b; }

int main(int argc, char const *argv[])
{
	while(~scanf("%d", &totnum) && totnum != 0){
		totlen = 0;
		for(int i = 0; i < totnum; ++i){
			scanf("%d", sticklen+i);
			totlen += sticklen[i];
		}
		sort(sticklen, sticklen+totnum, cmp);
		for(singlelen = sticklen[0]; singlelen <= totlen/2; ++singlelen){
			if(totlen%singlelen==0) {
				requirenum = totlen/singlelen;
				if(check(0, 0, 0)) { break; }
			}
		}
		if(singlelen>totlen/2){ printf("%d\n", totlen);}
		else {printf("%d\n", singlelen);}
	}
	return 0;
}

bool check(int curlen, int position, int finishnum)
{
	static bool flag[64] = {false};
	bool ans = false;
	if(curlen == singlelen){
		if(++finishnum == requirenum) {
			ans = true;
		} else {
			for(position=0;flag[position];++position);
			flag[position] = true;
			ans = check(sticklen[position], position+1, finishnum);
			flag[position] = false;
		}
	} else if(curlen < singlelen) {
		int prelen = 0, newlen;
		for(int pos = position; pos<totnum; ++pos){
			if(flag[pos] || sticklen[pos] == prelen) { continue; }
			prelen = sticklen[pos];
			newlen = curlen+prelen;
			flag[pos] = true;
			ans = check(newlen,pos+1,finishnum);
			flag[pos] = false;
			if(ans || newlen==singlelen || curlen == 0) { break; }
		}
	}
	return ans;
}