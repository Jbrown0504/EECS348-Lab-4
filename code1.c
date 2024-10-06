#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int scores[5];
bool checkscore(int td2,int td1,int td,int fg,int sft,int score){
    int total_score = td2*8+td1*7+td*6+fg*3+sft*2;
    if(total_score=score){
        return true;
    } else {
        return false;
    }
}
void printscore(int td2,int td1,int td,int fg,int sft){
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",td2,td1,td,fg,sft);
}
int figurescores(int score) {  
    int base_safeties;
    int base_fg; 
    if(score%2 == 0) { //calculates the base amount of safeties and iterates off that
        base_safeties = score/2;
        scores[4] = base_safeties;
    }
    else{
        base_safeties = floor(score/2)-1;
        scores[4] = base_safeties;
        scores[3]=base_fg=1;
    }
    printscore(scores[0],scores[1],scores[2],scores[3],scores[4]);
    for(int i=scores[4]-3;i>=2;i-=3){ //iterates through possible combinations of safeties and field goals
        scores[3]+=2;
        printscore(scores[0],scores[1],scores[2],scores[3],i);    
    }
    for(int i=base_safeties-3;i>=0;i-=3){ //iterates through possible combinations of touchdowns, safeties and field goals
        scores[3]=base_fg;
        scores[2]+=1;  
        printscore(scores[0],scores[1],scores[2],scores[3],i);
        for(int n=i-3;n>=2;n-=3){ 
            scores[3]+=2;
            printscore(scores[0],scores[1],scores[2],scores[3],n);    
        }
    }
    if(base_fg=1){
        for(int i=base_safeties-2;i>=0;i-=3){ //iterates through possible combinations of touchdowns, safeties and field goals
        scores[3]=0;
        scores[2]=0;
        scores[1]+=1;  
        printscore(scores[0],scores[1],scores[2],scores[3],i);
        for(int n=i-3;n>=2;n-=3){ 
            scores[3]+=2;
            printscore(scores[0],scores[1],scores[2],scores[3],n);    
            }
        }
    }   
}
int main() {
    int score;
    printf("Input score: ");
    scanf("%d", &score);
    figurescores(score);
}