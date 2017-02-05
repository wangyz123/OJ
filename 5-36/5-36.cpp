//5-36 ������������   (15��)
//����Ҫ���д���򣬼���2�������ĺ͡�������̡�
//
//�����ʽ��
//������һ���а���a1 b1 a2 b2�ĸ�ʽ����2������C1=a1+b1i��C2=a2+b2i��ʵ�����鲿����Ŀ��֤C2��Ϊ0��
//
//�����ʽ��
//�ֱ���4���а���(a1+b1i) ����� (a2+b2i) = ����ĸ�ʽ˳�����2�������ĺ͡�������̣����־�ȷ��С�����1λ��
//��������ʵ�������鲿Ϊ0���������������Ϊ0�������0.0��
//
//��������1��
//2 3.08 -2.04 5.06
//
//�������1��
//(2.0+3.1i) + (-2.0+5.1i) = 8.1i
//(2.0+3.1i) - (-2.0+5.1i) = 4.0-2.0i
//(2.0+3.1i) * (-2.0+5.1i) = -19.7+3.8i
//(2.0+3.1i) / (-2.0+5.1i) = 0.4-0.6i
//
//��������2��
//1 1 -1 -1.01	
//
//�������2��
//(1.0+1.0i) + (-1.0-1.0i) = 0.0
//(1.0+1.0i) - (-1.0-1.0i) = 2.0+2.0i
//(1.0+1.0i) * (-1.0-1.0i) = -2.0i
//(1.0+1.0i) / (-1.0-1.0i) = -1.0

#include <stdio.h>
#define ZERO 0.05;

struct cplx {
	double re;
	double im;
};

int isZero(double x) {
	if (x < 0) x = -x;
	return x < ZERO;
}

void putNum(struct cplx z) {
	if (isZero(z.re)) {
		if (isZero(z.im)) {
			printf("0.0");
		}
		else printf("%.1lfi", z.im);
	}
	else {
		printf("%.1lf", z.re);
		if (!isZero(z.im)) {
			printf("%+.1lfi", z.im);
		}
	}
}
void putLine(struct cplx z1, char c, struct cplx z2, struct cplx z3) {
	printf("(%.1lf%+.1lfi)", z1.re, z1.im);
	printf(" %c ", c);
	printf("(%.1lf%+.1lfi)", z2.re, z2.im);
	printf(" = ");
	putNum(z3); printf("\n");
}

struct cplx add(struct cplx z1, struct cplx z2) {
	struct cplx ans;
	ans.re = z1.re + z2.re;
	ans.im = z1.im + z2.im;
	return ans;
}

struct cplx minus(struct cplx z1, struct cplx z2) {
	struct cplx ans;
	ans.re = z1.re - z2.re;
	ans.im = z1.im - z2.im;
	return ans;
}

struct cplx product(struct cplx z1, struct cplx z2) {
	struct cplx ans;
	ans.re = z1.re * z2.re - z1.im * z2.im;
	ans.im = z1.re * z2.im + z2.re * z1.im;
	return ans;
}

struct cplx conj(struct cplx z) {
	struct cplx ans;
	ans.re = z.re;
	ans.im = -z.im;
	return ans;
}

struct cplx devide(struct cplx z1, struct cplx z2) {
	struct cplx ans;
	double denominator = z2.re * z2.re + z2.im * z2.im;
	struct cplx numerator = product(z1, conj(z2));
	ans.re = numerator.re / denominator;
	ans.im = numerator.im / denominator;
	return ans;
}

int main() {
	struct cplx z1, z2;
	scanf("%lf%lf%lf%lf", &z1.re, &z1.im, &z2.re, &z2.im);
	putLine(z1, '+', z2, add(z1, z2));
	putLine(z1, '-', z2, minus(z1, z2));
	putLine(z1, '*', z2, product(z1, z2));
	putLine(z1, '/', z2, devide(z1, z2));
	return 0;
}

