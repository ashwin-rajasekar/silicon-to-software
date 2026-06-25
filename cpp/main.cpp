char const    src_string[] = "hello world ";
char volatile dst_string[] = "something else";

struct Object {
	Object(){ dst_string[0] = '!'; }
	~Object(){ dst_string[0] = 'H'; }
} object;

int main(){
	char const* src = src_string;
	char volatile* dst = dst_string;
	while(*src){ *dst++ = *src++; }
}