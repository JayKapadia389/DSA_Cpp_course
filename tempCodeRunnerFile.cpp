if((W - v[i][1]) >= 0){
            W-= v[i][1];
            val+=v[i][0];
        }
        else{
            val+= v[i][0] * W / v[i][1];
            break ;    
            }