using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace ServerCore
{
    //SendBuffer는 Clean의 개념이 없다. -> 한명한테만 보내는게 아니라 1:n으로 전송하는 것이라 그렇다.
    public class SendBufferHelper
    {
        //raceCondition이 발생하지 않도록 이 클래스 내부에서만 접근 가능한 쓰레드를 생성(멀티쓰레드 고려)
        public static ThreadLocal<SendBuffer> CurrentBuffer = new ThreadLocal<SendBuffer>(() => { return null; });
        public static int ChunkSize { get; set; } = 4096 * 100;

        public static ArraySegment<byte> Open(int reserveSize)
        {
            if (CurrentBuffer.Value == null)                        //valuecheck -> null -> 사용안함
                CurrentBuffer.Value = new SendBuffer(ChunkSize);    //새로 만든다

            if (CurrentBuffer.Value.FreeSize < reserveSize)         //요구사항보다 작다면 기존의 chunk를 날린다음 새로 만들어버린다.
                CurrentBuffer.Value = new SendBuffer(ChunkSize);
            //이상 CurrentBuffer의 공간이 남아 있다는 뜻

            return CurrentBuffer.Value.Open(reserveSize);
        }

        public static ArraySegment<byte> Close(int usedSize)
        {
            return CurrentBuffer.Value.Close(usedSize);
        }
    }

    //여기서 다른쓰레드가 쓰기는 안하고 읽기만 하므로 raceCondition을 덜 고려해도 된다.
    public class SendBuffer
    {
        byte[] _buffer; //전역으로 만들면 raceCondition이 발생한다.
        int _usedSize;

        public int FreeSize { get { return _buffer.Length - _usedSize; } }

        public SendBuffer(int chunkSize)    //chunk는 덩어리란 뜻으로 뒤지게 크단 뜻이다.
        {
            _buffer = new byte[chunkSize];
        }

        public ArraySegment<byte> Open(int reserveSize)
        {
            if (reserveSize > FreeSize)
                return null;

            return new ArraySegment<byte>(_buffer, _usedSize, reserveSize);
            //버퍼사이즈 중 요청 영역을 할당하는 부분
        }

        public ArraySegment<byte> Close(int usedSize)
        {
            //확정적으로 사용할 버퍼의 크기를 정한 경우
            ArraySegment<byte> segment = new ArraySegment<byte>(_buffer, _usedSize, usedSize);
            _usedSize += usedSize;
            return segment;
        }
        
    }
}
