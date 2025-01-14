#pragma once


#include <nextalign/nextalign.h>
#include <nextalign/private/nextalign_private.h>
#include <nextclade/nextclade.h>

#include <ostream>
#include <string>
#include <vector>


namespace Nextclade {
  NextcladeResult analyzeOneSequence(        //
    const std::string& seqName,              //
    const NucleotideSequence& ref,           //
    const NucleotideSequence& query,         //
    const GeneMap& geneMap,                  //
    const std::vector<PcrPrimer>& pcrPrimers,//
    const QcConfig& qcRulesConfig,           //
    const Tree& tree,                        //
    const NextalignOptions& nextalignOptions //
  );


  inline std::ostream& operator<<(std::ostream& os, const NucleotideSubstitution& val) {
    os << "{ ";
    os << "refNuc: " << nucToString(val.refNuc) << ", ";
    os << "pos: " << val.pos << ", ";
    os << "queryNuc: " << nucToString(val.queryNuc);
    os << " }";
    return os;
  }

  inline std::ostream& operator<<(std::ostream& os, const NucleotideInsertion& val) {
    os << "{ ";
    os << "pos: " << val.pos << ", ";
    os << "length: " << val.length << ", ";
    os << "ins: '";
    for (const auto& v : val.ins) {
      os << nucToString(v);
    }
    os << "' }";
    return os;
  }

  inline std::ostream& operator<<(std::ostream& os, const NucleotideDeletion& val) {
    os << "{ ";
    os << "start: " << val.start << ", ";
    os << "length: " << val.length;
    os << " }";
    return os;
  }

  inline std::ostream& operator<<(std::ostream& os, const NucleotideRange& val) {
    os << "{ ";
    os << "nuc: " << nucToString(val.character) << ", ";
    os << "begin: " << val.begin << ", ";
    os << "end: " << val.end << ", ";
    os << "length: " << val.length;
    os << " }";
    return os;
  }

  inline std::ostream& operator<<(std::ostream& os, const AminoacidRange& val) {
    os << "{ ";
    os << "nuc: " << aaToString(val.character) << ", ";
    os << "begin: " << val.begin << ", ";
    os << "end: " << val.end << ", ";
    os << "length: " << val.length;
    os << " }";
    return os;
  }

  inline std::ostream& operator<<(std::ostream& os, const AminoacidSubstitution& val) {
    os << "{ ";
    os << "gene: \"" << val.gene << "\", ";
    os << "refAA: " << val.refAA << ", ";
    os << "queryAA: " << val.queryAA << ", ";
    os << "codon: " << val.codon << ", ";
    os << "codonNucRange: " << val.codonNucRange << ", ";
    os << "refContext: " << val.refContext << ", ";
    os << "queryContext: " << val.queryContext << ", ";
    os << "contextNucRange: " << val.contextNucRange;
    os << " }";
    return os;
  }

  inline std::ostream& operator<<(std::ostream& os, const AminoacidDeletion& val) {
    os << "{ ";
    os << "gene: \"" << val.gene << "\", ";
    os << "refAA: " << val.refAA << ", ";
    os << "codon: " << val.codon << ", ";
    os << "codonNucRange: " << val.codonNucRange << ", ";
    os << "refContext: " << val.refContext << ", ";
    os << "contextNucRange: " << val.contextNucRange;
    os << " }";
    return os;
  }
}// namespace Nextclade
