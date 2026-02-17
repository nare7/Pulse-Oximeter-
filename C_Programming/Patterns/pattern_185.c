#include<stdio.h>
void main(){
    int n;
    printf("Enter the no of rows...\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	for(int k=n;k>=i;k--){
		printf(" ");
	}
        for(int j=1;j<=n;j++){
        	printf("*");
} 
        printf("\n");
    }
}
