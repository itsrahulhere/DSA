class Solution
{
    boolean leaf(Node node){
        return (node.left==null && node.right==null);
    }
    
    void addLeft(Node node, ArrayList<Integer> list){
         if (node==null) return;
         
         if(leaf(node)){
             list.add(node.data);
         }
         else if(node.left!=null){
             list.add(node.data);
             addLeft(node.left, list);
         }
         else if(node.right!=null){
             list.add(node.data);
             addLeft(node.right, list);
         }
    }
    void addRight(Node node, ArrayList<Integer> list){
        if (node==null) return;
         
         if(leaf(node)){
             list.add(node.data);
         }
         else if(node.left!=null){
             list.add(node.data);
             addLeft(node.left, list);
         }
         else if(node.right!=null){
             list.add(node.data);
             addLeft(node.right, list);
         }
    }
    
	ArrayList <Integer> boundary(Node node)
	{
	    ArrayList<Integer> list = new ArrayList<>();
	    if(node==null) return list;
	    
	    list.add(node.data);
	    addLeft(node.left, list);
	    addRight(node.right, list);
	    return list;
	}
}