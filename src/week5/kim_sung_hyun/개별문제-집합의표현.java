import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class Main {
	static int parents[];
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer s = new StringTokenizer(in.readLine()," ");
		int N = Integer.parseInt(s.nextToken()); // 1~N
		int M = Integer.parseInt(s.nextToken());
		parents = new int[N+1];
		MakeSet();
		for (int i = 0; i < M; i++) {
			s = new StringTokenizer(in.readLine()," ");
			int select = Integer.parseInt(s.nextToken());
			int n1 = Integer.parseInt(s.nextToken());
			int n2 = Integer.parseInt(s.nextToken());
			if(select == 0) //유니온
				merge(n1,n2);
			else if(select == 1)
			{
				if(FindSet(n1) == FindSet(n2)) // 부모가 같냐/
					System.out.println("YES");
				else
					System.out.println("NO");
			}
		}
	}
	private static int FindSet(int x) {
		if(parents[x] == x)
			return x;
		return parents[x]=FindSet(parents[x]);
	}
	private static void merge(int u,int v) {
		int x = FindSet(u);
		int y = FindSet(v);

		if(x != y)
			parents[x] = y;
	}

	private static void MakeSet() {
		for (int i = 1; i < parents.length; i++)
			parents[i] = i;
	}
}
