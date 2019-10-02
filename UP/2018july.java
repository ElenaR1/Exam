import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.Vector;
public class Keys {
	public int numOfDigits(int a) {
		int count=0;
		while(a>0) {
			count++;
			a/=10;
		}
		return count;
	}
	public int[] toArray(int a) {
		int numOfDigits=numOfDigits(a);
		int[] result=new int[numOfDigits];
		for (int i = numOfDigits-1; i >=0; i--) {
			result[i]=a%10;
			a/=10;
		}
		return result;
	}
	public void print(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]+" ");
		}
		System.out.println();
	}
	public int compareInts(int a,int b) {
		int aLen=numOfDigits(a);
		int bLen=numOfDigits(b);
		int[] aarr=toArray(a);
		int[] barr=toArray(b);
		for (int i = 0; i < aLen && i<bLen; i++) {
			if(aarr[i]==barr[i]) {
				continue;
			}
			else {
				int res=aarr[i]-barr[i];
				return res;
			}
		}
		if(aLen<bLen) {
			return -1;
		}
		else if(aLen>bLen) {
			return 1;
		}
		else
			return 0;
	}
	public void sortLex(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr.length-1; j++) {
				if(compareInts(arr[j],arr[j+1])>0) {
					int temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
		
		print(arr);
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub	
		int[] arr= {13,14,7,2018,9,0};
		Keys obj=new Keys();
		obj.sortLex(arr);
		
	}

}
