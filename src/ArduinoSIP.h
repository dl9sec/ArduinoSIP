/* ====================================================================

   Copyright (c) 2018 Juergen Liegner  All rights reserved.
   (https://www.mikrocontroller.net/topic/444994)
   
   Copyright (c) 2019 Thorsten Godau (dl9sec)
   (Created an Arduino library encapsulation from the original code and did
   some beautification)
   
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   1. Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.

   3. Neither the name of the author(s) nor the names of any contributors
      may be used to endorse or promote products derived from this software
      without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) AND CONTRIBUTORS "AS IS" AND
   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR(S) OR CONTRIBUTORS BE LIABLE
   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
   OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
   OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
   SUCH DAMAGE.

   ====================================================================*/
#ifndef ARDUINO_SIP_H
#define ARDUINO_SIP_H

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <WiFiUdp.h>
   
class Sip
{
  public:
    Sip(char *pBuf, size_t lBuf);
	~Sip();
    
	
	void        Init(const char *SipIp, int SipPort, const char *MyIp, int MyPort, const char *SipUser, const char *SipPassWd, int MaxDialSec = 10);
    bool        Dial(const char *DialNr, const char *DialDesc = "");
	void		Processing(char *pBuf, size_t lBuf);
    bool        IsBusy() { return iRingTime != 0; }	
	
  private:
    char       *pbuf;
    size_t      lbuf;
    char        caRead[256];

    const char *pSipIp;
    int         iSipPort;
    const char *pSipUser;
    const char *pSipPassWd;
    const char *pMyIp;
    int         iMyPort;
    const char *pDialNr;
    const char *pDialDesc;

    uint32_t    callid;
    uint32_t    tagid;
    uint32_t    branchid;

    int         iAuthCnt;
    uint32_t    iRingTime;
    uint32_t    iMaxTime;
    int         iDialRetries;
    int         iLastCSeq;
    
	WiFiUDP 	Udp;
	
	void        HandleUdpPacket(const char *p);
	void        AddSipLine(const char* constFormat , ... );
    bool        AddCopySipLine(const char *p, const char *psearch);
    bool        ParseParameter(char *dest, int destlen, const char *name, const char *line, char cq = '\"');
    bool        ParseReturnParams(const char *p);
    int         GrepInteger(const char *p, const char *psearch);
    void        Ack(const char *pIn);
    void        Cancel(int seqn);
    void        Bye(int cseq);
    void        Ok(const char *pIn);
    void        Invite(const char *pIn = 0);

    uint32_t    Millis();
    uint32_t    Random();
    int         SendUdp();
    void        MakeMd5Digest(char *pOutHex33, char *pIn);

};

#endif	// ARDUINO_SIP_H