int main(int ac, char**av){
    for(int i=0;i<ac-1;i++)
    {
        printf("%c",atoi(av[i+1]));
    }
}
