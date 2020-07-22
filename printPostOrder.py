preorder = list(map(int,input().split()))
inorder = list(map(int,input().split()))

def printPostOrder(preorder,inorder):
	n=len(preorder)
	if n==0:
		return
	root=preorder[0]
	L=inorder.index(root)
	printPostOrder(preorder[1:L+1],inorder[0:L])
	printPostOrder(preorder[L+1:n],inorder[L+1:n])
	print(root,end=' ')
	
printPostOrder(preorder,inorder)
