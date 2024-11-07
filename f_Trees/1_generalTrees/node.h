#include <cstdlib>

struct node {
	node **children;
	int num_child;
	node *parent;
	int elem;

    int depth() {
		// TODO implementation [+10 pts]
        if(parent == nullptr){
            return 0;
        }
        return parent->depth() + 1;
	}


    int height() {
		// TODO implementation [+15 pts]
        if(num_child == 0){
            return 0;
        }
        
        int maxH = 0;
        
        for(int i = 0; i < num_child; i++){
            int tempH = children[i]->height();
            if(tempH > maxH){
                maxH = tempH;
            }
        }
        
        return maxH + 1;
    }
};