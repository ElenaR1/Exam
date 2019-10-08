import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.Vector;
public class Keys {

	public boolean isRowSorted(String[] arr) {
		for (int i = 0; i < arr.length-1; i++) {
			if(arr[i].compareTo(arr[i+1])>0) {
				return false;
			}
		}
		return true;
	}
	public void revealPassword(int m,int n, String[][] mat) {
		boolean[] rowSorted=new boolean[m];
		for (int i = 0; i < rowSorted.length; i++) {
			rowSorted[i]=false;
		}
		int numRowsSorted=0;
		for (int i = 0; i < m; i++) {
			if(isRowSorted(mat[i])) {
				numRowsSorted++;
			}
		}
		System.out.println(numRowsSorted);
		String[] middleWords=new String[numRowsSorted];
		int index=0;
		int middleIndex=n/2;
		for (int i = 0; i < m; i++) {
			if(!isRowSorted(mat[i]))
				continue;
			else {
				middleWords[index]=mat[i][middleIndex];
				index++;
			}
		}
		
		print(middleWords);
		for (int i = 0; i < middleWords.length; i++) {
			int wordLen=0;
			//System.out.println(middleWords[i]);
			String temp=middleWords[i];
			for (int j = 0; j < temp.length(); j++) {
				if(temp.charAt(j)==' ') {
					System.out.print(wordLen+" ");
					wordLen=0;
				}
				else {
					wordLen++;
				}
			}
			System.out.print(wordLen+" ");
		}
		System.out.println();
		
	}
	
	public void print(String[] arr) {
		int n=arr.length;
		for(int i=0;i<n;i++) {
			System.out.print(arr[i]+" ");
		}
		System.out.println();
	}
	public void printMat(int[][] arr) {
		int n=arr.length;
		for(int i=0;i<n;i++) {
			for (int j = 0; j < arr.length; j++) {
				System.out.print(arr[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println();
	}
	public void printMats(String[][] arr) {
		int n=arr.length;
		for(int i=0;i<n;i++) {
			for (int j = 0; j < arr.length; j++) {
				System.out.print(arr[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println();
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub	
		String[] arr=new String[]{"c","ab"};
		String arr2[]= {"aaa","bbb"};
		Keys obj=new Keys();
		obj.print(arr);
		obj.print(arr2);
		
		int[][] mat= {{1,2},{3,4}};
		int [][] m=new int[][]{{1,2},{3,4}}; 
		obj.printMat(mat);
		obj.printMat(m);
		
		String[][]mm= {{"aaa","bbb"},{"cc","dd"}};
		String[][]mmm= new String[][]{{"aaa","bbb"},{"cc","dd"}};
		obj.printMats(mm);
		obj.printMats(mmm);
		
		String[][] a= {{"Алгебра", "Аналитична геометрия", "Математически анализ"},
				{ "Увод в програмирането", "Обектно-ориентирано програмиране", "Структури от данни и програмиране"},
				{ "Бази от данни", "Изкуствен интелект", "Функционално програмиране"}};
		obj.printMats(a);
		System.out.println(obj.isRowSorted(arr));
		obj.revealPassword(3, 3, a);
		
		String s="abcd";
		System.out.println(s.length()+" "+s.charAt(2));
	}

}
