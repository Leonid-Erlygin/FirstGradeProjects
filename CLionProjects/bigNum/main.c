#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_BASE 8
#define BASE 100000000
struct bn_s
{
    int *body;
    int size;
    int sign;
};
typedef struct bn_s bn;

enum bn_codes{
    BN_OK, BN_NULL_OBJECT, BN_NO_MEMORY, BN_DIVIDE_BY_ZERO
};
//creation of new example
//const char *bn_to_string(bn* const object, int radix);
bn *bn_new()
{
    bn *r = (bn *)malloc(sizeof(bn));
    if (r == NULL) return NULL;
    r->sign = 0;
    r->size = 1;
    r->body = (int *)malloc((r->size)*sizeof(int));
    if (r->body == NULL) {
        free(r);
        return NULL;
    }
    r->body[0] = 0;

    return r;
}
int bn_delete(bn *t)
{
    free(t->body);

    free(t);
    return 1;
}
void toRadix (long long int x,long long int r,char *string){
    if(x>0){
        toRadix(x/r, r,string);
        char c[2];
        c[0] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[x%r];
        c[1] = '\0';
        strcat(string,c);
    }
}
int bn_abs(bn *t){
    t->sign = 1;
    return 0;
}
void zeroskip(bn *object){
    if(object->size!=1)while(object->body[object->size-1]==0)object->size--;
    if(object->size == 0)object->size++;
}
int bn_cmp(bn const *left, bn const *right)//Если левое меньше правого, will return -1

{

    if(left->sign == -1 && right->sign == 1) return -1;
    if(left->sign == 1 && right->sign == -1) return 1;
    if(left->sign == 0 && right->sign == 1)return -1;
    if(left->sign == 0 && right->sign == -1)return 1;
    if(left->sign == 1 && right->sign == 0)return 1;
    if(left->sign == -1 && right->sign == 0)return -1;

    if(left->sign == right->sign )
    {
        if(left->size>right->size){if(left->sign == 1){ return 1;}else return -1;}
        if(left->size<right->size){if(left->sign == 1) {return -1;}else return 1;}
        if(left->size==right->size)
        {
            int i = left->size-1;
            //printf("%c\n", 'T');
            while(i>=0&&left->body[i]==right->body[i]){
                i--;

            }
            //printf("%d\n",i );
            if(i == -1){return 0;}else{
                if(left->body[i]<right->body[i]){
                    if(left->sign==1) {return -1;} else return 1;
                }

                else {
                    if(left->sign==1){return 1;}else return -1;
                }
            }
        }
    }
    return 0;
};
/*
const char *bn_to_string(bn const *t, int radix)//(probably works)
{
    int size = t->size * (NUM_BASE+1);
    char *s = (char *) malloc (sizeof(char)*size);
    s[0] = '\0';
    char zero [2];
    zero[0]='0';
    zero[1]= '\0';
    if(t->size == 1 && t->body[0]==0){

        s = strcat(s, zero);
        return s;
    } else {
        int x;


        char minus[2];
        minus[0] = '-';
        minus[1] = '\0';
        char zero1[NUM_BASE+2];
        zero1[0] = '\0';

        int j = 0;
        while(j<NUM_BASE){
            strcat(zero1,zero);
            j++;
        }
        int i = t->size-1;



        if(t->sign == -1)strcat(s, minus);
        while(t->body[i]==0)
        {

            i--;
        }
        char m[13];
        m[0] = '\0';
        sprintf(m, "%d", t->body[i]);
        strcat(s, m);
        i--;

        while(i>=0){
            x = t->body[i];
            char str[13];
            str[0] = '\0';

            if(x == 0){strcat(s,zero1);}
            else{
                sprintf(str, "%d", x);
                while(((10*x)/BASE) == 0){

                    x = x*10;

                    strcat(s,zero);
                }
            }
            strcat(s,str);
            i--;
        }
        return s;
    }


}
*/
bn *bn_add_without_sign(const bn *left,const bn *right)//(works)
{

    if(left->size > right->size){
        int size = left->size;
        int *r = (int *) malloc (sizeof(int)*(size+1));
        int i;

        long long sum = 0;
        for (i = 0; i < right->size; ++i)
        {
            sum = (long long)right->body[i] + (long long)left->body[i] + sum;
            r[i] = (int)(sum % BASE);
            sum = sum / BASE;

        }
        int cursor = right->size;

        while(cursor < left->size && sum % BASE !=0 ){
            sum = sum + (long long)left->body[cursor];
            r[cursor] = (int)(sum % BASE);
            sum = sum / BASE;
            cursor++;

        }
        if (cursor == left->size)
        {
            r[cursor] = (int)(sum % BASE);
            bn *ret = bn_new();
            free(ret->body);
            ret->body = r;
            ret->size = size+1;
            ret->sign = 1;
            return ret;
        }else{

            for (i = cursor; i < left->size; ++i)
            {
                r[i] = left->body[i];
            }
            bn *ret = bn_new();
            free(ret->body);
            ret->body = r;
            ret->size = left->size;
            ret->sign = 1;
            return ret;
        }

    }else/*When rigth>=left*/{
        if(right->size == 1 && left->size == 1 && right->body[0] == 0 && left->body[0] == 0 ){
            bn *ret = bn_new();
            return ret;
        }else{

            int size = right->size;
            int *r = (int *) malloc (sizeof(int)*(size+1));
            r[size-1] = 0;
            int i;
            long long sum = 0;
            for (i = 0; i < left->size; ++i)
            {


                sum = (long long)right->body[i] + (long long)left->body[i] + sum;
                r[i] = (int)(sum % BASE);
                sum = sum / BASE;

            }

            int cursor = left->size;

            while(cursor < right->size && sum % BASE !=0 ){
                sum = sum + (long long)right->body[cursor];
                r[cursor] = (int)(sum % BASE);
                sum = sum / BASE;
                cursor++;

            }
            if (cursor == right->size)
            {
                r[cursor] = (int)(sum % BASE);
                bn *ret = bn_new();
                free(ret->body);

                ret->body = r;
                ret->size = size+1;
                ret->sign = 1;
                return ret;
            }else{

                for (i = cursor; i < right->size; ++i)
                {
                    r[i] = right->body[i];
                }
                bn *ret = bn_new();
                free(ret->body);
                ret->body = r;
                ret->size = right->size;
                ret->sign = 1;
                return ret;
            }
        }
    }

    return NULL;
}


bn *bn_sub_without_sign(const bn *left, const bn *right){//(done)
    if(left->size > right->size){
        int size = left->size;
        int *r = (int *) malloc (sizeof(int) * (left->size+1));
        r[left->size] = 0;
        int i;
        int sub = 0;
        for (i = 0; i < right->size; ++i)
        {
            sub = left->body[i] - right->body[i];
            if(sub<0){
                sub = sub + BASE;
                left->body[i+1] = left->body[i+1] - 1;
                r[i] = sub;
            }else{

                r[i] = sub;
            }



        }

        int cursor = right->size;
        //printf("%d\n",left->body[cursor] );
        while(left->body[cursor]<0){

            r[cursor] = BASE - 1;
            cursor++;
            left->body[cursor] = left->body[cursor]-1;


        }
        while(cursor<left->size){
            r[cursor] = left->body[cursor];
            cursor++;
        }
        bn *t = bn_new();
        free(t->body);
        t->body = r;
        t->size = size;
        t->sign = 1;
        return t;
    }else{//если правый >= левого
        if(right->size > left->size){
            int size = right->size;
            int *r = (int *) malloc (sizeof(int) * (right->size+1));
            r[right->size] = 0;
            int i;
            int sub = 0;
            for (i = 0; i < left->size; ++i)
            {
                sub = right->body[i] - left->body[i];
                if(sub<0){
                    sub = sub + BASE;
                    right->body[i+1] = right->body[i+1] - 1;
                    r[i] = sub;
                }else{

                    r[i] = sub;
                }



            }

            int cursor = left->size;
            //printf("%d\n",left->body[cursor] );
            while(right->body[cursor]<0){

                r[cursor] = BASE - 1;
                cursor++;
                right->body[cursor] = right->body[cursor]-1;


            }
            while(cursor<right->size){
                r[cursor] = right->body[cursor];
                cursor++;

            }

            bn *t = bn_new();
            free(t->body);
            t->body = r;
            t->size = size;
            t->sign = -1;
            return t;

        }else{
            //сравним числа
            int indic;

            int i = left->size-1;
            while(i>=0&&left->body[i]==right->body[i]){
                i--;

            }
            if(i == -1){indic = 0;}else{
                if(left->body[i]<right->body[i]){
                    indic = -1;
                }
                if(left->body[i]>right->body[i])indic = 1;
            }
            //printf("%d\n",i );
            /*printf("%d\n", left->body[i-1]);
            printf("%d\n", right->body[i-1]);*/

            //printf("%d\n",indic );
            int size = left->size+1;

            int *r = (int *) malloc(sizeof(int)*size);
            r[size-1] = 0;
            if (indic == -1)
            {
                bn *t = bn_new();
                free(t->body);
                t->size = size;
                t->sign = -1;
                int i = 0;
                int sub;
                for (i = 0; i < left->size; ++i)
                {
                    sub	= right->body[i] - left->body[i];
                    if(sub<0){
                        sub = sub + BASE;
                        right->body[i+1] = right->body[i+1] - 1;
                        r[i] = sub;
                    }else{
                        r[i] = sub;
                    }
                }
                r[left->size-1] = right->body[left->size-1] - left->body[left->size-1];
                t->body = r;
                t->sign = -1;
                return t;
            }
            if(indic == 1){
                bn *t = bn_new();
                free(t->body);
                t->size = left->size;
                t->sign = 1;
                int i = 0;
                int sub;
                for (i = 0; i <left->size; ++i)
                {
                    sub	= left->body[i] - right->body[i];
                    if(sub<0){
                        sub = sub + BASE;
                        left->body[i+1]--;
                        r[i] = sub;
                    }else{
                        r[i] = sub;
                    }
                }
                r[left->size-1] = left->body[left->size-1] - right->body[left->size-1];

                t->body = r;

                t->sign = 1;
                zeroskip(t);
                return t;
            }
            if(indic == 0){
                bn *t = bn_new();
                free(r);
                return t;

            }

        }
    }
    return NULL;
}

//int to big number(works)
int bn_init_int(bn *t,int init_int){
    if(init_int == 0){
        free(t->body);
        int *r = (int *) malloc (sizeof(int));
        r[0] = 0;
        t->body = r;
        t->size = 1;
        t->sign = 0;
    }
    if (init_int<0)
    {
        t->sign = -1;
    }
    if(init_int>0)
    {
        t->sign = 1;
    }
    free(t->body);
    int x = 0;
    int k;
    k = init_int;
    while(k!=0){
        x++;
        k = k / BASE;
    }

    //printf("%d\n", x);
    int y;
    int i = 0;
    int *r = (int *)malloc(x*sizeof(int));
    while(init_int!=0){
        y = init_int%BASE;
        //printf("%d\n", y);
        init_int = init_int/BASE;
        r[i] = y;
        i++;
    }
    t->size = x;
    t->body = r;
    return 0;
}


//string to big number
int bn_init_string(bn *t, const char *init_string){//does work
    if(init_string[0] == '-'){
        int numw = ((strlen(init_string)+NUM_BASE-2)/NUM_BASE);
        int *r = (int *) malloc (sizeof(int)* numw);

        t->sign = -1;

        int i = 0;
        char s[NUM_BASE+1];

        int len = strlen(init_string);
        int j = 0;
        i = len - NUM_BASE;
        while(i >= 1)
        {
            strncpy(s, &init_string[i], NUM_BASE);
            s[ NUM_BASE ] = '\0';
            //puts(s);
            r[j] = atoi(s);
            j++;
            i = i - NUM_BASE;
        }
        i = i +  NUM_BASE;

        char s1[NUM_BASE+1];
        strncpy(s1, &init_string[1], i-1);
        s1[i-1] = '\0';
        if(i != 1)r[j] = atoi(s1);
        free(t->body);
        t->body = r;
        t->size = numw;

    }else{
        int numw = ((strlen(init_string)+NUM_BASE-1)/NUM_BASE);
        int *r = (int *) malloc (sizeof(int)* numw);

        t->sign = 1;

        int i = 0;
        char s[NUM_BASE+1];

        int len = strlen(init_string);
        int j = 0;
        i = len - NUM_BASE;
        while(i >= 0)
        {
            strncpy(s, &init_string[i], NUM_BASE);
            s[ NUM_BASE ] = '\0';
            //puts(s);
            r[j] = atoi(s);
            j++;
            i = i - NUM_BASE;
        }
        i = i +  NUM_BASE;

        const int ii = i;
        char s2[ii+1];

        strncpy(s2, &init_string[0], i);
        s2[ i ] = '\0';
        //printf("%s\n",s2 );

        if(i != 0)r[j] = atoi(s2);
        free(t->body);
        t->body = r;
        t->size = numw;
    }
    return 0;
}

int bn_add_to(bn *t, bn const *right)//done
{
    if(t->sign*right->sign>0){
        bn *tmp;
        tmp = bn_add_without_sign(t,right);
        free(t->body);
        t->size = tmp->size;
        t->body = tmp->body;
        free(tmp);
    }else{
        if(t->sign == -1){
            bn *tmp;
            tmp = bn_sub_without_sign(right,t);
            free(t->body);
            t->size = tmp->size;
            t->body = tmp->body;
            t->sign = tmp->sign;
            free(tmp);

        }
        if (right->sign == -1)
        {
            bn *tmp;
            tmp = bn_sub_without_sign(t,right);
            free(t->body);
            t->size = tmp->size;
            t->body = tmp->body;
            t->sign = tmp->sign;
            free(tmp);
        }
    }
    return 1;
}



int bn_sub_to(bn *t, bn const *right)//done
{
    if(t->sign == 1 && right->sign == 1){
        bn *tmp;
        tmp = bn_sub_without_sign(t,right);

        free(t->body);
        t->size = tmp->size;
        t->body = tmp->body;
        t->sign = tmp->sign;
        free(tmp);
    }
    if(t->sign == 1 && right->sign == -1){
        bn *tmp;
        tmp = bn_add_without_sign(t,right);
        free(t->body);
        t->size = tmp->size;
        t->body = tmp->body;
        free(tmp);
    }
    if(t->sign == -1 && right->sign == 1){
        bn *tmp;
        tmp = bn_add_without_sign(t,right);
        free(t->body);
        t->size = tmp->size;
        t->body = tmp->body;
        free(tmp);
    }
    if(t->sign == -1 && right->sign == -1){
        bn *tmp;

        tmp =  bn_sub_without_sign(right, t);
        free(t->body);
        t->size = tmp->size;
        t->body = tmp->body;
        t->sign = tmp->sign;
        free(tmp);
    }


    return 0;
};


bn* bn_add(bn const *left, bn const *right){
    if(left->sign*right->sign>0){
        bn *tmp;
        tmp = bn_add_without_sign(left,right);

        tmp->sign = left->sign;
        return(tmp);

    }else{
        if(left->sign == -1){
            bn *tmp;
            tmp = bn_sub_without_sign(right,left);
            return tmp;

        }
        if (right->sign == -1)
        {
            bn *tmp;
            tmp = bn_sub_without_sign(left,right);
            return tmp;
        }//done
        return NULL;

    }

}
bn* bn_sub(bn const *left, bn const *right){
    if(left->sign == 1 && right->sign == 1){
        bn *tmp;
        tmp = bn_sub_without_sign(left,right);
        return tmp;
    }
    if(left->sign == 1 && right->sign == -1){
        bn *tmp;
        tmp = bn_add_without_sign(left,right);
        tmp->sign = left->sign;
        return tmp;
    }
    if(left->sign == -1 && right->sign == 1){
        bn *tmp;
        tmp = bn_add_without_sign(left,right);
        tmp->sign = left->sign;
        return tmp;
    }
    if(left->sign == -1 && right->sign == -1){
        bn *tmp;

        tmp =  bn_sub_without_sign(right, left);
        return tmp;
    }//done
    return NULL;
}


bn *bn_multiply(bn const *left, bn const *right){
    if((left->size == 1 && left->body[0] == 0)||(right->size == 1 && right->body[0] == 0)){
        return bn_new();
        //printf("%s\n","3" );
    }else{
        int *r = (int *) calloc (sizeof(int),(left->size + right->size + 1));
        r[left->size + right->size] = 0;

        int i, j;
        long long temp;
        long long mn;
        long long carry;
        for (i = 0; i < right->size; ++i)
        {
            carry = 0;
            mn = (long long)right->body[i];



            for (j = 0; j < left->size; j++)
            {
                temp = mn * (long long)left->body[j] + carry + (long long)r[i + j];
                r[i + j] =  (int)(temp%BASE);
                carry = temp / BASE;

            }
            r[i + left->size] = (int)carry;

        }
        bn *tmp = bn_new();
        free(tmp->body);
        tmp->body = r;
        tmp->sign = 1;
        tmp->size = left->size + right->size + 1;
        return tmp;
    }
    return NULL;
}

int bn_mul_to(bn *t, bn const *right)
{
    if(t->sign * right->sign < 0){
        bn *ret = bn_multiply(t,right);
        t->sign = -1;
        free(t->body);
        t->body = ret->body;
        t->size = ret->size;
        free(ret);

    }else{
        bn *ret = bn_multiply(t,right);

        t->sign = 1;
        free(t->body);
        t->body = ret->body;
        t->size = ret->size;
        free(ret);

    }
    return 0;
};






bn* bn_mul(bn const *left, bn const *right)
{
    if(left->sign * right->sign < 0){
        bn *tmp = bn_multiply(left,right);
        tmp->sign = -1;
        return tmp;
    }else{
        bn *tmp = bn_multiply(left,right);
        tmp->sign = 1;
        return tmp;
    }
    return NULL;
};






//bn copy(Building...)
bn *bn_init(bn const *orig)
{
    bn *tmp = bn_new();
    free(tmp->body);
    tmp->size = orig->size;
    int *r = (int *) malloc (sizeof(int)*orig->size);
    for (int i = 0; i < orig->size; ++i)
    {
        r[i] = orig->body[i];
    }
    tmp->body = r;
    tmp->sign = orig->sign;
    return tmp;
}
int bn_neg(bn *t){
    if(t->sign == -1){
        t->sign = 1;
        return 0;
    }else{
        t->sign = 1;
        return 0;
    }
    return 0;
}

int bn_sign(bn const *t)
{
    if(t->sign == -1){

        return -1;
    }
    if (t->sign == 1)
    {
        return 1;
    }else{
        return 0;
    }

    return 0;
}

//add to Big number q = x + y;(Bilging...)(ready for same sign)

//delete bn
/*
bn * fact(int number){
	bn * sum = bn_new();
	bn * prev = bn_new();
	bn * one = bn_new();
	char *s = "2";
	char *l = "1";

	bn *a = bn_new();
	bn *b = bn_new();
	bn_init_string(prev, s);
	bn_init_string(one, l);

	bn * ret;
	sum->body[0] = 1;

	for (int i = 0; i < number-1; ++i)
	{
		ret = bn_mul(prev,sum);
		bn_add_to(prev,one);
		//printf("%s\n",bn_to_string(prev,10) );
		free(sum->body);
		free(sum);
		sum = ret;


	}
	return ret;
}
*/
/*void bn_invert(bn* number){//wtf

    int shift = -1;
    int x = number->body[number->size-1];
    while(x/BASE == 0){
        shift++;
        x = x * 10;
    }
    //printf("%d\n",shift );
    int pow = 1;

    for (int i = 0; i < shift; ++i)
    {
        pow = pow *10;
    }
    int negPow = BASE/pow;
    for (int i =  number->size-1 ; i >0; --i)
    {

        number->body[i] = pow*number->body[i] + (number->body[i-1]/negPow);
        number->body[i-1] = number->body[i-1]%negPow;
    }

}*/
/*
void bn_div31(bn *left, bn *right,int *quotient, bn **remainder){
	int indic = 0;
	int i = right->size-1;
	while(left->body[i+1]==right->body[i])i--;
	if(left->body[i+1]<right->body[i]){
		indic = 0;
	}else{
		indic = 1;
	}
	//printf("%d\n",indic );
	if(indic == 1){
		bn *to_add = bn_new();
		bn_init_int(to_add,BASE);
		bn *div = bn_init(right);
		//printf("%s\n",bn_to_string(to_add,10) );
		bn_mul_to(right,to_add);
		while(right->body[right->size-1]==0)right->size--;
		//printf("%d\n", right->size);
		//printf("%s\n",bn_to_string(right,10) );
		//printf("%s\n",bn_to_string(left,10) );
		bn_sub_to(left,right);
		int k = 0;
		if(left->body[left->size-1]==0)k = 1;
		while(left->body[left->size-1]==0)left->size--;
		left->size = left->size + k;
		printf("%s\n",bn_to_string(left,10) );
		bn_div31(left,div,quotient,remainder);
		int q = *quotient;
		//printf("%d\n",q );
		*quotient = q + BASE;


	}else{
		long long q = (BASE*left->body[left->size-1]+left->body[left->size-2])/right->body[right->size-1];
		printf("%d\n", q);

		if(q>BASE - 1)q = BASE-1;
		bn *div = bn_init(right);

		int * Norm1 = (int *) malloc(sizeof(int)*(right->size+1));
		Norm1[right->size] = 0;
		long long carry = 0;
		long long mn;
		for (int i = 0; i < right->size; ++i)
		{
			mn = q*right->body[i]+carry;
			Norm1[i] = (int)(mn%BASE);
			carry = mn/BASE;
		}
		//printf("%d\n",carry );
		//right->size = right->size+1;
		Norm1[right->size] = carry;
		free(right->body);
		right->body = Norm1;
		right->size = right->size+1;

		//printf("%s\n",bn_to_string(right,10) );

		//printf("%d\n",right->body[right->size] );
		while(right->body[right->size-1] == 0)right->size--;
		//printf("%s\n",bn_to_string(right,10) );
		if(bn_cmp(right,left) == 1){
			bn_sub_to(right,div);
			q--;
			//printf("%d\n", q);
		}
		if(bn_cmp(right,left) == 1){
			bn_sub_to(right,div);
			q--;
			//printf("%d\n", q);
		}
		*quotient = q;

		*remainder = bn_sub(left,right);
		//printf("%d\n",quotient );
		//printf("%s\n",bn_to_string(remainder,10) );

	}
}

void bn_divsion(bn *object,bn const *diviser,bn *quotient, bn *remainder){
	int c = bn_cmp(object,diviser);
	if(c == -1){
		bn_delete(remainder);
		remainder = bn_init(object);
	}
	if(c == 0){
		quotient->body[0] = 1;

	}
	if(c == 1){
		int sizeDiv = diviser->size;
		bn * diviser1 = bn_init(diviser);
		int x = BASE/10;
		if(diviser1->body[diviser1->size-1]/x == 0)bn_invert(diviser1);
		if(object->body[object->size-1]/x == 0)bn_invert(object);
		int d = (BASE-1)/diviser1->body[sizeDiv-1];
		//printf("%d\n",d );
		bn *dTmp = bn_new();
		bn_init_int(dTmp,d);
		//printf("%s\n",bn_to_string(dTmp,10) );
		int * Norm1 = (int *) malloc(sizeof(int)*sizeDiv);
		long long carry = 0;
		long long mn;
		for (int i = 0; i < sizeDiv; ++i)
		{
			mn = d*diviser1->body[i]+carry;
			Norm1[i] = (int)(mn%BASE);
			carry = mn/BASE;
		}
		int * Norm2 =  (int *) malloc(sizeof(int)*(object->size + 1));
		carry = 0;
		for (int i = 0; i < object->size; ++i)
		{
			mn = d*object->body[i]+carry;
			Norm2[i] = (int)(mn%BASE);
			carry = mn/BASE;
		}
		Norm2[object->size] = carry;

		bn* diviserNorm = bn_new();
		bn* objectNorm = bn_new();
		free(diviserNorm->body);
		free(objectNorm->body);
		diviserNorm->body = Norm1;
		diviserNorm->size = sizeDiv;
		objectNorm->body = Norm2;
		objectNorm->size = object->size + 1;

		printf("%d\n",d );
		printf("%s\n",bn_to_string(objectNorm,10) );
		printf("%s\n",bn_to_string(diviserNorm,10) );

		while(diviserNorm->body[diviserNorm->size-1] == 0)diviserNorm->size--;
		while(objectNorm->body[objectNorm->size-1] == 0)objectNorm->size--;
		sizeDiv = diviserNorm->size-1;
		int n = sizeDiv;
		int m = object->size-1 - n;
		int *r2 = (int *) malloc (sizeof(int)*(m+1));
		r2[m] = 0;
		for (int j = m;  j >=0 ; j--)
		{
			int tmp = (BASE * objectNorm->body[j + n] + objectNorm->body[n+j-1]);
			int q = tmp / (diviserNorm->body[sizeDiv] );
			int r = tmp % (diviserNorm->body[sizeDiv] );
			while(((q*diviserNorm->body[sizeDiv-1] > BASE*r + diviserNorm->body[j + n - 2])||q == BASE) && r < BASE){
				q--;
				r = r + diviserNorm->body[sizeDiv];
			}
			long long carry = 0;
			int borrow = 0;
				int mn = q;
				long long temp;
				int sum;

				for (int i = 0; i <= sizeDiv; i++)
				{
					temp = mn * (long long)diviserNorm->body[i] + carry;
					sum = objectNorm->body[j+i] - (int)(temp%BASE) - borrow;
					if(sum<0){
						borrow = 1;
						objectNorm->body[j+i] = BASE + sum;
						carry = temp / BASE;
					}else{
						borrow = 0;
						objectNorm->body[j+i] = sum;
					carry = temp / BASE;
					}
				}
				objectNorm->body[n+j +1 ] = objectNorm->body[n+j +1 ] - carry;
				//возможно нужно будет добавить сложение

				r2[j-1] = q;
		}
		free(quotient->body);
		quotient->body = r2;
		quotient->size = m+1;
		//int *r1 = (int *) malloc (sizeof(int)*n);
		for (int i = 0; i < n; ++i)
		{
			r1[n-1-i] = objectNorm[n+m]/q;
			o
		}
		bn_delete(dTmp);

	}


}
void shift(bn *object){
	for (int j = object->size;j>=1;j--) object->body[j] = object->body[j-1];
		if(object->body[object->size]!=0)object->size++;
}
*/
int bn_cmp_abs(bn const *left, bn const *right){
    if(left->size>right->size){ return 1;}
    if(left->size<right->size){return -1;}
    if(left->size==right->size)
    {
        int i = left->size-1;
        while(i>=0&&left->body[i]==right->body[i]){
            i--;

        }
        if(i == -1){return 0;}else{
            if(left->body[i]<right->body[i]){
                return -1;
            }

            else {
                return 1;
            }
        }
    }
    return 0;
}/*
void showme(bn* right,const bn *left){

    printf("%s\n",bn_to_string(right,10) );
    printf("%d\n",right->size );
    printf("%d\n",right->sign );
    printf("%s\n"," " );
    if(left!=NULL){
        printf("%s\n",bn_to_string(left,10) );
        printf("%d\n",left->size );
        printf("%d\n",left->sign );
        printf("%s\n"," " );
    }
}*/


void insert(bn *object,int val){//добавляет число в начало
    if(object->size == 1 && object->body[0] == 0){object->body[0] = val;}else{
        for (int i = object->size; i >=1 ; --i)
        {
            object->body[i] = object->body[i-1];
        }
        object->body[0] = val;
        object->size++;
    }
}
int binsearch(bn *to_div,bn const *right){//curent == right, but size == rigth->size + 1;

    int x = 0;
    int l = 0;
    int r = BASE;
    while(l <= r){

        int m = (l+r) >> 1;
        //умножение на m;
        bn *mm = bn_new();
        bn_init_int(mm,m);
        bn* curent = bn_mul(right,mm);
        zeroskip(curent);
        bn_delete(mm);

        //showme(curent,NULL);
        if(bn_cmp_abs(curent,to_div)<=0){
            x = m;
            l = m+1;
        }else{

            r = m - 1;
        }
        bn_delete(curent);
    }
    //printf("%d\n", x);
    return x;
}


int isZERO(const bn *object){
    if(object->size == 1 && object->body[0] == 0){return 1;}else{return 0;}
    return 0;
}

void to_divinit(bn* to_div,int n){
    int *r =(int*) malloc(sizeof(int)*(n + 1));
    for (int i = 0; i <to_div->size; ++i) {
        r[i] = to_div->body[i];
    }
    free(to_div->body);
    to_div->sign = 1;
    to_div->body = r;

}
bn* bn_division(bn const *left, bn const *right){// работает для положительных



    bn * to_div = bn_new();
    to_div->body = (int *)realloc(to_div->body,sizeof(int)*(left->size + 1));
    to_div->size = 1;
    to_div->sign = 1;
    to_div->body[0] = 0;


    bn *result = bn_new();
    result->body = (int *)realloc(result->body,sizeof(int)*(left->size + 1));
    result->size = left->size;

    int x=0;
    for (int i = left->size-1; i >=0; --i)
    {

        insert(to_div,left->body[i]);
        zeroskip(to_div);
        if(bn_cmp_abs(to_div,right)<0 )x = 0;
        if(bn_cmp_abs(to_div,right)==0)x = 1;
        if(bn_cmp_abs(to_div,right)>0)x = binsearch(to_div,right);

        if(isZERO(to_div)) x = 0;
        //printf("%d\n",x );
        if(x == 0){
            result->body[i] = x;
            //printf("%d\n",x );
            continue;

        }else{
            bn *mm = bn_new();
            bn_init_int(mm,x);

            bn * copyRight = bn_mul(right,mm);
            zeroskip(copyRight);
            bn_delete(mm);
            //showme(copyRight,NULL);
            bn_sub_to(to_div,copyRight);
            //showme(to_div,NULL);
            //printf("%d\n",x );
            to_divinit(to_div,left->size);
            result->body[i] = x;
            bn_delete(copyRight);
        }


    }
    //bn_delete(copyRight);
    bn_delete(to_div);
    return result;

}


bn* bn_div(bn const *left, bn const *right)
{
    if(bn_cmp_abs(left,right)<0){
        return bn_new();
    }
    if(right->sign*left->sign < 0){
        bn* ret = bn_division(left,right);
        zeroskip(ret);
        bn* tmp = bn_multiply(ret,right);
        zeroskip(tmp);
        if(bn_cmp_abs(tmp,left)==0){
            ret->sign = -1;
            bn_delete(tmp);
            return ret;
        } else{
            bn *one = bn_new();
            ret->sign = 1;
            bn_init_int(one,1);
            bn_add_to(ret,one);
            ret->sign = -1;
            bn_delete(one);
            bn_delete(tmp);
            return ret;
        }

    }else{
        bn* ret = bn_division(left,right);
        ret->sign = 1;
        return ret;
    }
    return NULL;
};
bn* bn_mod(bn const *left, bn const *right)
{
    bn* tmp = bn_div(left,right);
    zeroskip(tmp);
    bn* mul = bn_mul(right,tmp);
    zeroskip(mul);
    bn* ret = bn_sub(left,mul);
    if(right->sign!=-1){ret->sign = 1;}
    else{ret->sign = -1;}
    zeroskip(ret);
    bn_delete(mul);
    bn_delete(tmp);
    return ret;
};
int bn_div_to(bn *t, bn const *right)
{
    bn *tmp = bn_div(t,right);
    free(t->body);
    t->body = tmp->body;
    t->sign = tmp->sign;
    t->size = tmp->size;
    free(tmp);
    return 0;
};




int bn_mod_to(bn *t, bn const *right){
    bn *tmp = bn_mod(t,right);
    free(t->body);
    t->body = tmp->body;
    t->sign = tmp->sign;
    t->size = tmp->size;
    free(tmp);
    return 0;
};
int bn_pow_to(bn *t, int degree){//быстро не возводится
    if(t->size == 1 && t->body[0]==1){
        if(t->sign==1){
            return 0;
        } else{
            if(degree%2==0){t->sign = 1;return 0;} else{
                return 0;
            }
        }
    } else {
        int sign = t->sign;
        bn *tmp = bn_init(t);
        bn *tmp2 = bn_init(t);
        int count = degree / 1000;
        if (count != 0) {
            for (int i = 0; i < 1000-1; ++i) {
                bn_mul_to(tmp2, tmp);
                zeroskip(tmp2);
            }
            bn *tmp3 = bn_init(tmp2);
            //bn_delete(t);
            free(t->body);
            t->body = tmp2->body;
            t->size = tmp2->size;

            for (int i = 0; i < count-1; ++i) {
                bn_mul_to(t, tmp3);
                //printf("%s\n",bn_to_string(t,10) );
            }
            for (int i = 0; i <degree%1000; ++i) {
                bn_mul_to(t, tmp);
                //printf("%s\n",bn_to_string(t,10) );
            }

            if(sign==-1){
                if(degree%2==0)t->sign=1; else t->sign = sign;
            }
            zeroskip(t);
            free(tmp2);
            bn_delete(tmp3);
            bn_delete(tmp);
            return 0;
        } else{
            bn *tmp3 = bn_init(tmp2);
            //bn_delete(t);
            free(t->body);
            t->body = tmp2->body;
            t->size = tmp2->size;
            for (int i = 0; i < degree-1; ++i) {
                bn_mul_to(t, tmp3);
                //printf("%s\n",bn_to_string(t,10) );
            }
            if(sign==-1){
                if(degree%2==0)t->sign=1; else t->sign = sign;
            }
            zeroskip(t);
            free(tmp2);
            bn_delete(tmp3);
            bn_delete(tmp);
            return 0;
        }


    }
    return 0;
}


int magicNumbers[38] = {0, 0,
                        62, 39, 31, 27, 24, 22, 20, 19, 18, 18, 17, 17, 16, 16, 15, 15, 15, 14,
                        14, 14, 14, 13, 13, 13, 13, 13, 13, 12, 12, 12, 12, 12, 12, 12, 12};
long long bn_to_long(bn* const object){
    long long ret;
    if(object->size == 1){
        ret = ( long long)object->body[0];
    }
    if(object->size == 2) {
        ret = (long long) object->body[0] + (long long) object->body[1] * BASE;
    }
    if(object->size == 3){
        ret = (long long) object->body[0] + (long long) object->body[1] * BASE + (long long) object->body[2] * BASE*BASE;
    }
    return ret;
}

char* addZeros(char *s,int number){
    char *zero = "0";
    char *zero1 = (char *)malloc(sizeof(char)*(number+1+strlen(s)));
    zero1[0] = '\0';
    for (int i = 0; i <number; ++i) {
        strcat(zero1,zero);
    }
    strcat(zero1,s);

    return zero1;

}
const char *bn_to_string(const bn *object, int radix){//totall mess
    if(radix == 10){
        int size = object->size * (NUM_BASE+1);
        char *s = (char *) malloc (sizeof(char)*size);
        s[0] = '\0';
        char zero [2];
        zero[0]='0';
        zero[1]= '\0';
        if(object->size == 1 && object->body[0]==0){

            s = strcat(s, zero);
            return s;
        } else {
            int x;


            char minus[2];
            minus[0] = '-';
            minus[1] = '\0';
            char zero1[NUM_BASE+2];
            zero1[0] = '\0';

            int j = 0;
            while(j<NUM_BASE){
                strcat(zero1,zero);
                j++;
            }
            int i = object->size-1;



            if(object->sign == -1)strcat(s, minus);
            while(object->body[i]==0)
            {

                i--;
            }
            char m[13];
            m[0] = '\0';
            sprintf(m, "%d", object->body[i]);
            strcat(s, m);
            i--;

            while(i>=0){
                x = object->body[i];
                char str[13];
                str[0] = '\0';

                if(x == 0){strcat(s,zero1);}
                else{
                    sprintf(str, "%d", x);
                    while(((10*x)/BASE) == 0){

                        x = x*10;

                        strcat(s,zero);
                    }
                }
                strcat(s,str);
                i--;
            }
            return s;
        }

    } else {
        if (isZERO(object)) {
            char *s = (char *) malloc(sizeof(char) * 2);
            s[0] = '0';
            s[1] = '\0';
            return s;
        } else {
            bn *d = bn_new();
            bn_init_int(d, radix);
            bn_pow_to(d, magicNumbers[radix]);//модуль для моего большого числа
            int numberwords = (object->size * NUM_BASE + 10) / 2;
            char **s = (char **) malloc(sizeof(char *) * numberwords);


            bn *tmp = bn_init(object);
            int index = 0;
            while (!isZERO(tmp)) {
                bn *q = bn_div(tmp, d);
                bn *mul = bn_mul(q,d);
                zeroskip(mul);
                bn *r = bn_sub(tmp, mul);
                zeroskip(r);
                zeroskip(q);
                char *stmp = (char *) malloc(sizeof(char) * (magicNumbers[radix] + 1));
                stmp[0] = '\0';
                toRadix(bn_to_long(r), radix, stmp);
                s[index] = stmp;


                bn_delete(tmp);
                tmp = q;
                zeroskip(tmp);
                bn_delete(r);
                bn_delete(mul);
                index++;

            }
            for (int i = 0; i < index - 1; ++i) {

                int num = magicNumbers[radix];
                int numLeadingZeros = num - strlen(s[i]);
                if (numLeadingZeros != 0) {
                    char *p = s[i];
                    s[i] = addZeros(p, numLeadingZeros);
                    free(p);
                }

            }
            char *ret = (char *) malloc(sizeof(char) * ((index + 1) * magicNumbers[radix]));
            ret[0] = '\0';
            if (object->sign < 0)strcat(ret, "-");
            for (int j = index - 1; j >= 0; --j) {
                strcat(ret, s[j]);
                free(s[j]);
            }


            free(s);


            //зачистка
            bn_delete(tmp);
            bn_delete(d);

            return ret;

        }
    }
    return NULL;
}


//radix initiliazation()(Bilding...)
int bn_init_string_radix(bn *t, const char *s, int radix){
    return 0;
}


int bn_root_to(bn *t, int reciprocal){
    bn* ret = bn_init(t);
    bn* d = bn_new();
    bn_init_int(d,reciprocal);

    for(;;){

        bn* a = bn_init(ret);
        bn_pow_to(a, reciprocal);
        bn_sub_to(a, t);

        bn* b = bn_init(ret);
        bn_pow_to(b, reciprocal - 1);

        bn_mul_to(b, d);
        zeroskip(b);
        bn* c = bn_div(a, b);
        zeroskip(c);
        bn_sub_to(ret, c);
        bn_delete(a);
        bn_delete(b);

        if (isZERO(c)) {
            bn_delete(c);
            break;
        }
        bn_delete(c);
    }
    for (;;) {
        bn* check = bn_init(ret);
        bn_pow_to(check,reciprocal);
        int indic = bn_cmp(check,t);
        bn_delete(check);
        if(indic<=0)break;
        ret->body[0]--;

    }
    bn_delete(d);
    free(t->body);
    t->body = ret->body;
    t->size = ret->size;
    free(ret);
    return 0;
}