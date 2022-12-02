FROM ubuntu:20.04

WORKDIR /usr/src/app

RUN apt-get update

RUN apt-get install -y wget
RUN apt-get install gnupg -y
RUN apt-get install tzdata -y
ENV TZ="America/New_York"
RUN apt-get install -y google-perftools

RUN wget -O -  https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -
RUN apt-get install libgoogle-perftools-dev -y
RUN echo "deb http://apt.llvm.org/bionic/ llvm-toolchain-bionic-11 main" | tee -a /etc/apt/sources.list
RUN apt-get update
RUN apt-get install libllvm-11-ocaml-dev libllvm11 llvm-11 llvm-11-dev llvm-11-doc  llvm-11-runtime \
    clang-11 clang-tools-11 clang-11-doc libclang-common-11-dev libclang-11-dev libclang1-11 clang-format-11 clangd-11 \
    libfuzzer-11-dev lldb-11 lld-11 libc++-11-dev libc++abi-11-dev libomp-11-dev -y
RUN update-alternatives \
  --install /usr/lib/llvm              llvm             /usr/lib/llvm-11         50 \
  --slave   /usr/bin/llvm-config       llvm-config      /usr/bin/llvm-config-11  \
	--slave   /usr/bin/llvm-ar           llvm-ar          /usr/bin/llvm-ar-11 \
	--slave   /usr/bin/llvm-as           llvm-as          /usr/bin/llvm-as-11 \
	--slave   /usr/bin/llvm-bcanalyzer   llvm-bcanalyzer  /usr/bin/llvm-bcanalyzer-11 \
	--slave   /usr/bin/llvm-cov          llvm-cov         /usr/bin/llvm-cov-11 \
	--slave   /usr/bin/llvm-diff         llvm-diff        /usr/bin/llvm-diff-11 \
	--slave   /usr/bin/llvm-dis          llvm-dis         /usr/bin/llvm-dis-11 \
	--slave   /usr/bin/llvm-dwarfdump    llvm-dwarfdump   /usr/bin/llvm-dwarfdump-11 \
	--slave   /usr/bin/llvm-extract      llvm-extract     /usr/bin/llvm-extract-11 \
	--slave   /usr/bin/llvm-link         llvm-link        /usr/bin/llvm-link-11 \
	--slave   /usr/bin/llvm-mc           llvm-mc          /usr/bin/llvm-mc-11 \
	--slave   /usr/bin/llvm-mcmarkup     llvm-mcmarkup    /usr/bin/llvm-mcmarkup-11 \
	--slave   /usr/bin/llvm-nm           llvm-nm          /usr/bin/llvm-nm-11 \
	--slave   /usr/bin/llvm-objdump      llvm-objdump     /usr/bin/llvm-objdump-11 \
	--slave   /usr/bin/llvm-ranlib       llvm-ranlib      /usr/bin/llvm-ranlib-11 \
	--slave   /usr/bin/llvm-readobj      llvm-readobj     /usr/bin/llvm-readobj-11 \
	--slave   /usr/bin/llvm-rtdyld       llvm-rtdyld      /usr/bin/llvm-rtdyld-11 \
	--slave   /usr/bin/llvm-size         llvm-size        /usr/bin/llvm-size-11 \
	--slave   /usr/bin/llvm-stress       llvm-stress      /usr/bin/llvm-stress-11 \
	--slave   /usr/bin/llvm-symbolizer   llvm-symbolizer  /usr/bin/llvm-symbolizer-11 \
	--slave   /usr/bin/llvm-tblgen       llvm-tblgen      /usr/bin/llvm-tblgen-11

RUN update-alternatives \
  --install /usr/bin/clang                 clang                  /usr/bin/clang-11    50 \
  --slave   /usr/bin/clang++               clang++                /usr/bin/clang++-11 \
  --slave   /usr/bin/lld                   lld                    /usr/bin/lld-11 \
  --slave   /usr/bin/clang-format          clang-format           /usr/bin/clang-format-11  \
  --slave   /usr/bin/clang-tidy            clang-tidy             /usr/bin/clang-tidy-11  \
  --slave   /usr/bin/clang-tidy-diff.py    clang-tidy-diff.py     /usr/bin/clang-tidy-diff-11.py \
  --slave   /usr/bin/clang-include-fixer   clang-include-fixer    /usr/bin/clang-include-fixer-11 \
  --slave   /usr/bin/clang-offload-bundler clang-offload-bundler  /usr/bin/clang-offload-bundler-11 \
  --slave   /usr/bin/clangd                clangd                 /usr/bin/clangd-11 \
  --slave   /usr/bin/clang-check           clang-check            /usr/bin/clang-check-11 \
  --slave   /usr/bin/scan-view             scan-view              /usr/bin/scan-view-11 \
  --slave   /usr/bin/clang-apply-replacements clang-apply-replacements /usr/bin/clang-apply-replacements-11 \
  --slave   /usr/bin/clang-query           clang-query            /usr/bin/clang-query-11 \
  --slave   /usr/bin/modularize            modularize             /usr/bin/modularize-11 \
  --slave   /usr/bin/sancov                sancov                 /usr/bin/sancov-11 \
  --slave   /usr/bin/c-index-test          c-index-test           /usr/bin/c-index-test-11 \
  --slave   /usr/bin/clang-reorder-fields  clang-reorder-fields   /usr/bin/clang-reorder-fields-11 \
  --slave   /usr/bin/clang-change-namespace clang-change-namespace  /usr/bin/clang-change-namespace-11 \
  --slave   /usr/bin/clang-import-test     clang-import-test      /usr/bin/clang-import-test-11 \
  --slave   /usr/bin/scan-build            scan-build             /usr/bin/scan-build-11 \
  --slave   /usr/bin/scan-build-py         scan-build-py          /usr/bin/scan-build-py-11 \
  --slave   /usr/bin/clang-cl              clang-cl               /usr/bin/clang-cl-11 \
  --slave   /usr/bin/clang-rename          clang-rename           /usr/bin/clang-rename-11 \
  --slave   /usr/bin/find-all-symbols      find-all-symbols       /usr/bin/find-all-symbols-11 \
  --slave   /usr/bin/lldb                  lldb                   /usr/bin/lldb-11 \
  --slave   /usr/bin/lldb-server           lldb-server            /usr/bin/lldb-server-11

COPY main.c compare.c compare.h .
COPY *.sh .

