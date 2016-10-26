void _analyseRawData(const char *bytesp)//这是对ipod数据的解析封装
    {
        string str(bytesp);
        
        int vLen = (int)str.size()/8;
        float sValue[vLen];

        for(int i=0;i<str.size()/8;i++)
        {
            string single(str,i*8,8);
            
            string correct;
            
            for(int i=3;i>=0;i--)
            {
                
                string split(single,i*2,2);
                correct.append(split);
            }
            
            uint32_t num;
            float f;
            sscanf(correct.c_str(), "%x", &num);
            f = *((float*)&num);
            sValue[i] = f;
        }
    
        int arrayCount = (vLen-1)/4;
        
        for(int i=1;i>=0;i--)//send acc data.
        {
            float value[5];
            
            for(int j=0;j<4;j++)
            {
                value[j] = sValue[i*4+j+1];
            }
            
            value[4] = sValue[0];
            
            bool isAcc = (i < 2);//pre 2 array would be acc data.
            
            SensorChecker::getInstance()->onCheckUpdate(isAcc,value);
        }
        
        for(int i=2;i<arrayCount;i++)//send acc data.
        {
            float value[5];
            
            for(int j=0;j<4;j++)
            {
                value[j] = sValue[i*4+j+1];
            }
            
            value[4] = sValue[0];
            
            bool isAcc = (i < 2);//pre 2 array would be acc data.
            
            SensorChecker::getInstance()->onCheckUpdate(isAcc,value);
        }
    }