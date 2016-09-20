#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char** argv)
{
	int fd1,fd2,ret;
	char i[1024]={0};
	if(argc != 3){
		printf("wrong\n");
		return 0;
	}
	fd1 = open(argv[1],O_RDONLY);
	fd2 = open(argv[2],O_WRONLY|O_TRUNC|O_CREAT,0640);
	if(fd1 < 0 || fd2 < 0){
		printf("wrong\n");
		return 0;
	}
	while((ret = read(fd1,i,1024)) > 0){
		write(fd2,i,ret);
	}
	if(ret < 0){
		printf("wrong\n");
		return 0;
	}
	close(fd1);
	close(fd2);
	return 0;
}

//int main()
//{
//	int fd1,fd2;
//	char i[100]={0},j='1';
//	fd1=open("test.log",O_WRONLY);
//	for(;j<=100;j++)
//		write(fd1,&j,1);
//	close(fd1);
//	fd1=open("test.log",O_RDONLY);
//	fd2=open("test1.log",O_WRONLY);
//	read(fd1,i,100);
//	printf("%s\n",i);
//	write(fd2,i,100);
//	close(fd1);
//	close(fd2);
//	fd1=open("test.log",O_WRONLY);
//	int ret;
//	char a[10]={0};
//	ret = read(0,a,10);
//	write(fd1,a,ret);
//	write(1,a,10);
//	close(fd1);
//	return 0;
//}
//int main (int argc,char** argv)
//{
//	int fd,ret;
//	char i[10]={0};
//	if(argc != 2){
//		printf("wrong\n");
//		return 0;
//	}
//	fd = open(argv[1],O_RDONLY);
//	if(fd<0){
//		printf("wrong\n");
//		return 0;
//	}
//	while(1)
//	{
//	ret = read(fd,i,10);
//	if(ret == 0)
//		break;
//	write(1,i,ret);
//	}
//	close(fd);
//	return 0;
//}
