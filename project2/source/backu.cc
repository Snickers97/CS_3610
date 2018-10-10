    bool isRoot = false;
            if(prev == node){
                isRoot = true;
                
            node->key = ptr->key;
            if(isRoot)
                node->right = NULL;
            else
                prev->left = NULL;
            delete ptr;
