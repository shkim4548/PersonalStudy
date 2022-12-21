using System;
using System.Collections.Generic;
using System.Text;

namespace ServerCore
{
    //패킷 송수신 과정을 만들기 위한 준비 단계
    public class RecvBuffer
    {
        ArraySegment<byte> _buffer; //큰 바이트 배열 사용시 부분적으로 잘라서 사용해야할 가능성을 고려한다.
        int _readPos;               //버퍼에서 현재 읽는 지점을 찍는다. 정상적인 경우 처리 후 writePos와 같은 지점으로 이동한다.
        int _writePos;              //버퍼에서 다 쓰고 제일 끝자리 지점을 찍는다. 즉 이 뒤부터는 비었다는 소리
        //커서와 같은 개념의 Pos 변수들, 버퍼내에서 특정 버퍼의 위치를 찍어주는 역할을 한다.

        public RecvBuffer(int buffersize)
        {
            _buffer = new ArraySegment<byte>(new byte[buffersize], 0, buffersize);
        }

        public int DataSize { get { return _writePos - _readPos; } }      //실제로 버퍼에 들어가 처리되지 않은 바이트의 수
        public int FreeSize { get { return _buffer.Count - _writePos; } }    //버퍼에 남은 공간

        public ArraySegment<byte> ReadSegment   //이제까지 받은 데이터의 유효범위의 segment 어디부터 읽으면 되는지를 컨텐츠단에 넘긴다.
        {
            get { return new ArraySegment<byte>(_buffer.Array, _buffer.Offset + _readPos, DataSize); }
        }

        public ArraySegment<byte> WriteSegment  //WritePos이후의 부분을 나타낸다
        {
            get { return new ArraySegment<byte>(_buffer.Array, _buffer.Offset + _writePos, FreeSize); }
        }

        public void Clean() //ReadPos와 WritePos를 처음부분으로 당겨서 버퍼를 비워주는 함수, 이걸 사용하지 않으면 송수신버퍼가 마비된다.
        {
            int dataSize = DataSize;
            if (dataSize == 0)
            {
                //남은 데이터가 없음 ReadPose==WritePos인 경우 -> 0 포지션으로 위치만 옮긴다.
                _readPos = _writePos = 0;
            }
            else
            {
                //남은 데이터가 있음 WritePos!=ReadPos인 경우 -> 시작 위치로 복사한다.
                Array.Copy(_buffer.Array, _buffer.Offset + _readPos, _buffer.Array, _buffer.Offset, dataSize);
                _readPos = 0;
                _writePos = dataSize;
            }
        }

        public bool OnRead(int numOfBytes)   //수신받은 데이터처리가 성공적인 경우 -> 커서 위치를 이동시킨다.
        {
            if (numOfBytes > DataSize)  //우선 Segmentation fault를 방지한다.
                return false;
            _readPos += numOfBytes;     //수신이 성공적이라면 성공적인 위치까지 readPos 커서를 뒤로 땡긴다.
            return true;
        }

        public bool OnWrite(int numOfBytes)  //클라에서 쏴버린 데이터를 서버가 Receive한 경우
        {
            if (numOfBytes > FreeSize)
                return false;
            _writePos += numOfBytes;
            return true;
        }
    }
}
