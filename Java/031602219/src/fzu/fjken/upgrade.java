//package fzu.fjken;
//
//
//import java.io.BufferedReader;
//import java.io.FileInputStream;
//import java.io.FileNotFoundException;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.HashMap;
//import java.util.List;
//import java.util.regex.Matcher;
//import java.util.regex.Pattern;
//
//class verTree{
//	int num = 0;
//	verTree[] child = new verTree[36];
//}
//
//class wordCount{
//	private int count;
//	private String word;
//	public int getCount() {
//		return count;
//	}
//	public void setCount(int count) {
//		this.count = count;
//	}
//	public String getWord() {
//		return word;
//	}
//	public void setWord(String word) {
//		this.word = word;
//	}
//}
//
//
//public class upgrade {
//
//	/**
//	 * @param args
//	 */
//		public static void main(String[] args) {
//		public static String text="";
//		public static List<String> list = new ArrayList<String>();
//		public static int linenum;
////		public static verTree root = new verTree();
//		
//		public static int countChar(String path,int count) throws IOException{
//			try {
//				FileInputStream file = new FileInputStream(path);	//�����ļ���
//				InputStreamReader reader = new InputStreamReader(file);	//�ļ�����ȡ
//				BufferedReader buffReader = new BufferedReader(reader);
//				String strline = "";
//				String blank_regex = "^\\s*$";
//				Pattern b_pat = Pattern.compile(blank_regex);
//		        while((strline = buffReader.readLine())!=null){
//		        	linenum+=1;	//ÿ����ȡ����һ��Ĭ�ϸ��д��ڻ��з�            
//		            text += strline + " ";	
//		            count+=strline.length()+linenum;
//		            Matcher b_mat = b_pat.matcher(strline);
//		            if(b_mat.matches())
//		            	linenum--;
////		            System.out.println(strline.length());
//		        }
//		        buffReader.close();		        
//			} catch (FileNotFoundException e) {
//				e.printStackTrace();
//			}finally{
//				text = text.toLowerCase();	//��д��ĸͬ��ת��ΪСд��ĸ
//			}
//			return count;
//		}
//		
//		public static int countVec(int count){
//			//�޳��ı��еķ���ĸ�����ֵĲ��ֲ��ԣ���Ϊ��ʱ�ķָ���
//			String regex ="[^0-9a-zA-Z]";	//"[\u4e00-\u9fa5]|\\s";
//			System.out.println(text);
//			Pattern pat = Pattern.compile(regex);
//			Matcher mat = pat.matcher(text);
//			text = mat.replaceAll("��");				
//			//���շָ�������
//			System.out.println(text);
//			String [] textArray = text.split("��+");
//			//�Ե�����ʽ����Լ��
//			String v_regex = "^[a-z]{4}[a-z0-9]*$";
//			for(String i:textArray){
//				Pattern v_pat = Pattern.compile(v_regex);
//				Matcher v_mat = v_pat.matcher(i);
//				if(v_mat.matches())
//					list.add(i);
//			}
////			System.out.println(list.size());
//			return list.size();
//		}
//		
//		public static int countLine(){
//			return linenum;
//		}
//		
//		
//		public static void verSort(String ver){
//			verTree p = root;
//			for(int i=0;i<ver.length();i++){
//				char single = ver.charAt(i);
//				if(single>='a' && single<='z'){
//					if(p.child[single-'a']==null)
//						p.child[single-'a'] = new verTree();
//					p=p.child[single-'a'];
//				}
//				else if(single>='0' && single<='9'){
//					if(p.child[single-'0']==null)
//						p.child[single-'0'+26] = new verTree();
//					p=p.child[single-'0'+26];
//				}
//			}	
//			p.num++;	
//		}
//		
//		public static HashMap<String, Integer> createTree(){
//			HashMap<String,Integer> ver = new HashMap<String, Integer>();
//			for(String i:list){
//				if(!ver.containsKey(i))
//					ver.put(i, 1);
//				else{
//					Integer num = ver.get(i);
//					ver.put(i, num+1);
//				}
//			}
//			return ver;
//		}
//
//	}
//
//}
