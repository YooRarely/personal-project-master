package HomeWork;


import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
/*
 * InputStreamReader(new FileInputStream(�����ļ���))�����ļ��Ķ�ȡ
 * BufferedReader(�ļ���ȡ)����readLine()�ķ���
 */

public class Main {
	   
	public static void main(String[] args)  {
		System.out.println("�������ļ�λ�ã�");
		Scanner scanner =new Scanner(System.in);
		try {
		    Lib.yourMethodName(scanner.nextLine());
		} catch(IOException e) {
			e.printStackTrace();
			// Your error handling method
			// If any error occurs, you should notify users about this exception here
		}
	// Remember to close any resources in the end
    scanner.close();
	}
}
