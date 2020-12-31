let project = new Project('lua-test');

project.kore = false;

project.addFile('Sources/**');
project.addDefine('LUA_IMPL');
project.addCFlag('LDFLAGS=-Wl,--no-as-needed');
project.addIncludeDir("Libraries/minilua");
project.setDebugDir('Deployment');

resolve(project);
