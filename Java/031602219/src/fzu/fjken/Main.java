package fzu.fjken;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.List;
import java.util.Map;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	
	public static void main(String[] args) throws IOException {
		int Origin = 0;
		String filepath = "D:\\Users\\30309\\Workspaces\\MyEclipse 10\\WordCount\\bin\\fzu\\fjken\\"+"input.txt"; //args[0];
		Writer file = new FileWriter("D:\\Users\\30309\\Workspaces\\MyEclipse 10\\WordCount\\bin\\fzu\\fjken\\"+"output.txt");
		BufferedWriter out = new BufferedWriter(file);
		
		int c_count = lib.countChar(filepath,Origin)-1;		//�ı���ĩβĬ���޻��У������޳�
		int v_count = lib.countVec(Origin);
		int l_count = lib.countLine();
		List<Map.Entry<String,Integer>> wordTree = lib.createTree();
		
		System.out.println("characters: " + c_count);
		out.write("characters: " + c_count+"\r\n");
		System.out.println("words: "+ v_count);
		out.write("words: "+ v_count+"\r\n");
		System.out.println("lines: "+ l_count);
		out.write("lines: "+ l_count+"\r\n");
		for(int i=0;i<wordTree.size();i++){
			System.out.println("<"+wordTree.get(i).getKey()+">: "+wordTree.get(i).getValue());
			out.write("<"+wordTree.get(i).getKey()+">: "+wordTree.get(i).getValue()+"\r\n");
		}
		out.flush(); // �ѻ���������ѹ���ļ�
		out.close(); // ���ǵùر��ļ�
	}
}
