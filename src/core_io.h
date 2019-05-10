// Copyright (c) 2009-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef VDS_CORE_IO_H
#define VDS_CORE_IO_H

#include <string>
#include <vector>

class CBlock;
class CBlockHeader;
class CScript;
class CTransaction;
class CMutableTransaction;
class uint256;
class UniValue;

// core_read.cpp
extern CScript ParseScript(const std::string& s);
extern bool DecodeHexTx(CMutableTransaction& tx, const std::string& strHexTx);
extern bool DecodeHexBlk(CBlock&, const std::string& strHexBlk);
extern bool DecodeHexBlkHdr(CBlockHeader&, const std::string& strHexBlkHdr);
extern uint256 ParseHashUV(const UniValue& v, const std::string& strName);
extern uint256 ParseHashStr(const std::string&, const std::string& strName);
extern std::vector<unsigned char> ParseHexUV(const UniValue& v, const std::string& strName);

// core_write.cpp
extern std::string FormatScript(const CScript& script);
extern std::string ScriptToAsmStr(const CScript& script, const bool fAttemptSighashDecode = false);
extern std::string EncodeHexTx(const CTransaction& tx, const int serializeFlags = 0);
extern std::string EncodeHexMTx(const CMutableTransaction& tx, const int serializeFlags = 0);
extern void ScriptPubKeyToUniv(const CScript& scriptPubKey,
                        UniValue& out, bool fIncludeHex);
extern void TxToUniv(const CTransaction& tx, const uint256& hashBlock, UniValue& entry);

#endif // VDS_CORE_IO_H
