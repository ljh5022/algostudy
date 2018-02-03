package proj_2;

import java.util.ArrayList;
import java.util.Stack;

public class Combination {
	ArrayList<Character> char_arr_for_com = new ArrayList<Character>();  //기준 배열
	Stack<Character> st;//조합을 저장할 스택
	ArrayList<Character> return_char_arr = new ArrayList<Character>(); // 반환할 배열 
	public Combination(ArrayList<Character> Char_arr)
	{
		for(int i=0; i<Char_arr.size(); i++)char_arr_for_com.add(Char_arr.get(i));	//배열을 받아 객체에 저장한다.
		st = new Stack<Character>(); //스택에 메모리를 할당한다.   
	}

	public void Store_Return_charArr()
	{		
		for(int i=0;i<st.size();i++)return_char_arr.add(st.get(i));//스택에 있는 값들을 ArrayList 에 저장한다.
	}
	public ArrayList<Character> Get_Store_Return_charArr(){	
//		for(int i=0;i<return_char_arr.size();i++){	   	// for value checking 
//			System.out.println(return_char_arr.get(i));
//		}
		return return_char_arr; } //
	
	
	
	public void doCombination( int n, int r, int index)
	{
		// n : 전체 개수
		// r : 뽑을 개수
		// index 배열이다보니 현재 배열의 어디를 가리키고 있는지 필요하므로.
		if(r==0){
			//0개를 뽑는다는건 더 이상 뽑을 것이 없다는 말과 같으므로  스택을 출력하고 함수를 종료한다.
			Store_Return_charArr();
			return;
		}
		else if(n==r){
			//nCr 이라는 건 나머지를 전부 뽑겠다는 말과 같으므로 전부 스택에 넣은 후 출력하면 된다.
			for(int i=0;i<n;i++)st.add(char_arr_for_com.get(index+i));//index부터 n개를 차례대로 스택에 넣고
			Store_Return_charArr(); //스택을 보여준다.
			for(int i=0;i<n;i++)st.pop(); //이후 전부 pop을 시켜 다음 과정을 진행한다.
		}
		else{
			//저 두가지 예외 사항을 빼면 점화식대로 진행하면 된다.

			//index를 포함하는 경우
			st.add(char_arr_for_com.get(index));
			doCombination(n-1,r-1,index+1); //index를 스택에 넣은상태로 index를 1옮겨 그대로 진행.

			//index를 포함하지 않는 경우
			st.pop(); //index를 제거해주고
			doCombination(n-1, r, index+1); //index를 제외한 상태에서 n-1Cr 진행.


		}
	}
}