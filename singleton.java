import java.util.ArrayList;

public class Singleton
{
	
	private static ArrayList<String> list = null;
	
	public static void add(String element)
	{
		list.add(element);
	}
	
		public static void remove(String element)
	{
		list.remove(element);
	}
	
	public static ArrayList<String> get()
	{
		return list;
	}
	
	private static Singleton singletonInstance = new Singleton();
	
	public static Singleton getInstance()
	{
		return singletonInstance;
	}

}
