static void uart_recv_data_analyzer( u8 *pucBuf, int ilen)
{
	int ret = 0;
	int datalen = 0;
    u8 *ph = pucBuf; //头指向pucBuf起始位置
    u8 *pt = pucBuf;
    int i;

    //找到完整的数据帧并处理
    for ( i = 0; i < ilen; i++)
    {
        if(((*ph) != UART_PREAMBLE_HEAD1) || (*(ph+1) != UART_PREAMBLE_HEAD2)) //找帧头位置
        {
            ph += 1;
            continue; //没找到就继续
        }
        pt++;
        if( (*pt == UART_PREAMBLE_TAIL1) && (*(pt + 1) == UART_PREAMBLE_TAIL2) && (*(pt + 2) == UART_PREAMBLE_TAIL3) ) //帧尾
        {
            pt += 3; //尾指针指向帧尾下一个字节
            i += 3; //计数跳过帧尾
            uart_recv_data_process(ph, pt-ph); //处理数据帧
            ph = pt; //头尾指针均指向帧尾下一个字节，继续寻找下一帧
            //uart_bus->write("ok", 2);
        }
        
        //printf("frame head check!\n");

        // printf("\n __this->checksum = %x \n", __this->checksum);
        
        //printf("verified \n");
    }
}
