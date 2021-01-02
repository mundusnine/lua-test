let project = new Project('lua-test');

project.kore = false;

project.addFile('Sources/**');
project.addDefine('LUA_IMPL');
project.addIncludeDir("Libraries/minilua");
project.addLib('dl');
project.setDebugDir('Deployment');

resolve(project);
