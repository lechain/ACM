#include <cstdio>

int main(int argc, char const *argv[]){
	int n,m,s,f;
	scanf("%d%d%d%d",&n,&m,&s,&f);
	int t=1, tag=s>f?-1:1, c=s>f?'L':'R';
	for(int i=0; i<m; ++i){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);		
		if(s==f){
			break;
		}
		for(;t<x;++t){
			putchar(c);
			if(f==(s+=tag)){
				break;
			}
		}
		if(s==f){
			break;
		}
		if(s>=y && s<=z || s+tag>=y && s+tag<=z){
			putchar('X');
		}else {
			putchar(c);
			if(f==(s+=tag)){
				break;
			}
		}
		++t;
	}
	for(;s!=f;putchar(c),s+=tag);
	return 0;
}